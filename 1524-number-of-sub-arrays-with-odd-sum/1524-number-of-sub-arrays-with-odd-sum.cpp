class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       
      int n= arr.size();
      int dp[n][2];
      int mod=1e9+7; 
     
      for(int i=0; i<n;i++){
          
          if(i==0){
              if(arr[i] %2==0){
                  dp[i][0]=1;
                  dp[i][1]=0;
              }else{
                  dp[i][0]=0;
                   dp[i][1]=1;
              }
             continue;
          }
          
          if(arr[i] % 2==0){
              
             dp[i][0]= (1+ dp[i-1][0])%mod;
              dp[i][1]= dp[i-1][1] % mod;
          }else{
              
              dp[i][0]= dp[i-1][1] % mod;
              dp[i][1]= (1+ dp[i-1][0])% mod;
          }
      }
        
       int ans=0;
        
       for(int i=0; i<n;i++){
           
           ans+= dp[i][1];
           ans%=mod;
       }
    
        return ans;
        
        
        
    }
};