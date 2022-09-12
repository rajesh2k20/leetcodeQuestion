class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
       multiset<int> s;
        
       for(int i=0; i<tokens.size();i++){
           s.insert(tokens[i]);
       }
        
       int score=0;
       int ans=0;
       while(s.size()>0){
           
           auto it= s.begin();
           
           if(power>= *it){
               power-= *it;
               score++;
               ans=max(ans, score);
               s.erase(it);
               
           }else if(score>=1 and s.size()>0){
               
               score--;
               auto it= s.end();
               it--;
               power+= *it;
               s.erase(it);
               
           }else{
               
               return ans;
           }
       }
        
        return ans;
    }
};