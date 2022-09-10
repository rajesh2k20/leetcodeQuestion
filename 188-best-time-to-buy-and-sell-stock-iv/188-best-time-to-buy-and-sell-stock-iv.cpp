int dp[1001][101];
class Solution {
public:
    int helper(int k, int index, vector<int> & arr){
        
        
        if(k==0){
            
            return 0;
        }
        
        if(index==arr.size()){
            
           return 0; 
        }
        if(dp[index][k] != -1){
            return dp[index][k];
        }
        int ans=helper(k, index+1, arr);
        for(int i=index+1; i<arr.size();i++){
            
          int currans= arr[i]-arr[index] + helper(k-1, i+1, arr);
            ans=max(ans, currans);
        }
        
        return dp[index][k]=ans;
        
        
    }
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        
        for(int i=0; i<=n;i++){
            
            for(int j=0; j<=k;j++){
                dp[i][j]=-1;
            }
        }
        return helper(k, 0, prices);
        
        
    }
};