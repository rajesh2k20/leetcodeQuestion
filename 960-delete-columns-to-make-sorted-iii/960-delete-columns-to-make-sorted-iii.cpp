int dp[101][101];
class Solution {
public:
    bool check(vector<string> & str, int c1, int c2){
        
        
        for(int i=0; i<str.size();i++){
            
             if(str[i][c1]>str[i][c2]){
                 return false;
             }
        }
        return true;
    }
    int helper(int index, int last, vector<string> & str){
        
        
        
        if(index==str[0].size()){
            
            return 0;
        }
        
        
        if(dp[index][last] !=-1){
            
            return dp[index][last];
        }
        
        
        
        if(last==0){
            
            int ans1=1+ helper(index+1, index+1, str);
            int ans2= helper(index+1, last, str);
            return dp[index][last]=max(ans1, ans2);
        }else {
            
           if(check(str, last-1, index)==true){
               
            int ans1=1+ helper(index+1, index+1, str);
            int ans2= helper(index+1, last, str);
            return dp[index][last]=max(ans1, ans2);
               
           }else{
               return dp[index][last]=helper(index+1, last, str);
           }
        }
    }
    int minDeletionSize(vector<string>& strs) {
        
        
      int last=0;
        
     int n=strs[0].size();
        
      for(int i=0; i<=n;i++){
          
          for(int j=0; j<=n;j++){
              
              dp[i][j]=-1;
          }
      }
        
        
        
      int ans= helper(0, last, strs);
        // cout<<ans<<endl;
      return strs[0].size()-ans;
        
        
    }
};