int dp[101][101];
class Solution {
public:
    
    int helper(int index, int endindex, int n, vector<int> & arr){
        
        if(n==0 || index>endindex){
            
            return 0;
        }
        
        if(dp[index][n] !=-1){
            
            return dp[index][n];
        }
        
        int taken= arr[index]+helper(index+2, endindex, n-1, arr);
        int notTaken= helper(index+1, endindex, n, arr);
        
        return dp[index][n]=max(taken, notTaken);
    }
    int rob(vector<int>& nums) {
        
      
     int n= nums.size();
        
      if(n==1){
          return nums[0];
      }
     if(n%2==0){
         memset(dp, -1, sizeof(dp));
         int ans1= helper(0, n-2, n/2, nums);
          memset(dp, -1, sizeof(dp));
         int ans2= helper(1, n-1, n/2, nums);
         return max(ans1, ans2);
     }else{
          memset(dp, -1, sizeof(dp));
         int ans1= helper(0, n-2,n/2, nums);
          memset(dp, -1, sizeof(dp));
         int ans2= helper(1, n-1, n/2, nums);
          memset(dp, -1, sizeof(dp));
         int ans3= helper(0, n-2, (n/2)+1, nums);
          memset(dp, -1, sizeof(dp));
         int ans4= helper(1, n-1, (n/2)+1, nums);
         return max({ans1, ans2, ans3, ans4});
     }
     
        
    }
};