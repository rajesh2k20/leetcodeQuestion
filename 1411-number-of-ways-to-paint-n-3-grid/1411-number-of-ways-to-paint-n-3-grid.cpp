class Solution {
public:
    int numOfWays(int n) {
      
     int dp[n][2];
     memset(dp,0, sizeof(dp));
     int mod=1e9+7;
     for(int i=0; i<n;i++){
         
         if(i==0){
             dp[i][1]=dp[i][0]=6;
             continue;
         }
         dp[i][1]= (1LL*((1LL*3*dp[i-1][1])%mod+ (1LL*2*dp[i-1][0])%mod))%mod;
         dp[i][0]= (1LL*((1LL*2*dp[i-1][1])%mod+ (2*dp[i-1][0])%mod))%mod;
         
     }
     return (1LL*(dp[n-1][0]+ dp[n-1][1]))%mod;
    }
};