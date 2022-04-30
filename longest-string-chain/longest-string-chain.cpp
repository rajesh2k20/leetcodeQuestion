bool cmp( string & str1, string & str2 ){
    
    
     return str1.size()<str2.size();
}
class Solution {
public:
    bool check( string & str1, string & str2){
        
        
         if(str2.size()<= str1.size()){
             return false;
         }
        
         if(str2.size()-str1.size()!=1){
             return false;
         }
        
        int i=0;
        int j=0;
        
        while(i<str1.size() && j<str2.size() ){
            
            if(str1[i]==str2[j]){
                i++;
                j++;
            }else{
                 j++;
            }
        }
        
        if(i==str1.size()){
            return true;
        }
        
        return false;
        
        
    }
    int longestStrChain(vector<string>& words) {
        
        
       sort( words.begin(), words.end(), cmp);
       int n= words.size();
        
       int dp[n];
        memset(dp, 0, sizeof(dp));
        int ans=1;
        for(int i=0; i<n;i++){
            
            dp[i]=1;
            
            for(int j=0; j<i;j++){
                
                if(check( words[j], words[i])==true){
                    
                    dp[i]= max(dp[i], dp[j]+1);
                }
            }
            
            ans=max( dp[i], ans);
        }
        
        return ans;
    
    }
};