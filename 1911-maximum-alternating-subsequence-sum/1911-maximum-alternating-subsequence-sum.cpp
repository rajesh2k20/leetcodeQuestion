
long long dp[(int)(1e5+1)][2];
class Solution {
public:
    long long helper(int index, int parity, vector<int> & nums){
        
        if(index==nums.size()){
            
            return 0;
        }
        if(dp[index][parity] !=-1){
            return dp[index][parity];
        }
        long long ans1=0;
        long long ans2= helper(index+1, parity, nums);
        if(parity==0){
            
           ans1= nums[index]+ helper(index+1, 1, nums);
         
        }else{
            ans1= -1*nums[index]+ helper(index+1, 0, nums);
        }
        
        return  dp[index][parity]=max(ans1, ans2);
    }
    long long maxAlternatingSum(vector<int>& nums) {
       
     memset(dp, -1, sizeof(dp));
      return helper(0, 0, nums);
        
    }
};