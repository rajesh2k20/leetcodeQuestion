class Solution {
public:
    int check(string & str1, string str2){
        
        int i=0;
        
        int j=0;
        
        while(i<str1.size() && j<str2.size()){
            
            
            if(str1[i]==str2[j]){
                j++;
            }
            i++;
        }
        
        if(j==str2.size()){
            
            return 1;
        }
        
        return 0;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
       
       
        int count=0;
        
        map<string, int> m;
        
        for(int i=0; i<words.size();i++){
            
            
           m[words[i]]++;
        }
        
        for(auto  x: m){
            
            int currans= check(s, x.first);
            count+= currans*x.second;
        }
        
        return count;
    }
};