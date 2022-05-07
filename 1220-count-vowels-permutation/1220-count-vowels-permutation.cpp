class Solution {
public:
    int countVowelPermutation(int n) {
      
     int dp[n][5];
     memset(dp,0, sizeof(dp));
      int mod=1e9+7;
     for(int i=0; i<n;i++){
         
        for(int j=0; j<5;j++){
            
            if(i==0){
                dp[i][j]=1;
                continue;
            }
            if(j==0){
                
            dp[i][j]+=dp[i-1][1];
            dp[i][j]%=mod;
            dp[i][j]+= dp[i-1][2];
            dp[i][j]%=mod;
            dp[i][j]+= dp[i-1][4];
            dp[i][j]%=mod;
                
            }else if(j==1){
                
            dp[i][j]+=dp[i-1][0];
            dp[i][j]%=mod;
            dp[i][j]+= dp[i-1][2];
            dp[i][j]%=mod;
           
                
            }else if(j==2){
                
            dp[i][j]+=dp[i-1][1];
            dp[i][j]%=mod;
            dp[i][j]+= dp[i-1][3];
            dp[i][j]%=mod;
            
                
            }else if(j==3){
                
            dp[i][j]+=dp[i-1][2];
            dp[i][j]%=mod;
           
                
            }else{
                
            dp[i][j]+=dp[i-1][3];
            dp[i][j]%=mod;
            dp[i][j]+= dp[i-1][2];
            dp[i][j]%=mod;
            
                
            }
        }
     }
     int ans=0;
     for(int i=0; i<5;i++){
         ans+= dp[n-1][i];
         ans%=mod;
     }
     return ans;
    }
};