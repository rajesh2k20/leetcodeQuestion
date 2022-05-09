class Solution {
public:
    int minFlipsMonoIncr(string str) {
      
     int n=str.size();
     int dp[n][2];
     memset(dp, 0, sizeof(dp));
     for(int i=0; i<n;i++){
         
         if(i==0){
             
             if(str[i]=='0'){
                 dp[i][0]=0;
                 dp[i][1]=1;
             }else{
                 dp[i][0]=1;
                 dp[i][1]=0;
             }
             continue;
         }
         
         if(str[i]=='0'){
             dp[i][0]= dp[i-1][0];
             dp[i][1]= min(dp[i-1][0], dp[i-1][1])+1;
         }else{
             dp[i][0]= 1+dp[i-1][0];
             dp[i][1]= min(dp[i-1][0], dp[i-1][1]);
         }
     }
        
        return min(dp[n-1][0], dp[n-1][1]);
    }
};