class Solution {
public:
    int firstUniqChar(string s) {
      
      int fre[26];
      int n=s.size();
        for(int i=0; i<26;i++){
            
            fre[i]=n;
        }
        
        for(int i=0; i<s.size();i++){
            
            int index= s[i]-'a';
            
            if(fre[index]==n){
                fre[index]=i;
            }else if(fre[index]<n){
                fre[index]=1e9;
            }
        }
        
        int minvalindex=n;
        
        for(int i=0; i<26;i++){
            
            minvalindex=min(minvalindex, fre[i]);
        }
        
        if(minvalindex==n){
            return -1;
        }else{
            return minvalindex;
        }
    }
};