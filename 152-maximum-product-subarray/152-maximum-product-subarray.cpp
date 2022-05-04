class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
     int n= nums.size();
     int dp[n][2];
     int ans=-1e9;
    for(int i=0; i<n;i++){
        
        if(i==0){
            dp[i][0]= nums[i];
            dp[i][1]=nums[i];
            ans=max(ans, dp[i][0]);
            continue;
        }
        
    
       dp[i][0]= min(dp[i-1][0]*nums[i], min(dp[i-1][1]*nums[i], nums[i]));
       dp[i][1]= max(dp[i-1][1]*nums[i], max( dp[i-1][0]*nums[i], nums[i]));
       ans=  max(ans, max(dp[i][0], dp[i][1]));
    }
    
     return ans;
     
    }
};