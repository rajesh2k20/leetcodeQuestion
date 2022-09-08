class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
      int dp[amount+1];
      dp[0]=0;
        
      for(int i=1; i<=amount;i++){
          
          dp[i]=1e9;
          for(int j=0; j<coins.size();j++){
              
              int val= i-coins[j];
              if(val>=0){
                  
                dp[i]= min(dp[i], 1+dp[val]);  
              }
          }
      }
        
     if(dp[amount]>=1e9){
         return -1;
     }else{
         return dp[amount];
     }
    }
};