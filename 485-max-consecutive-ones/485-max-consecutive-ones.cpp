class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
      int count=0;
      int ans=0;
    
      if(nums[0]==1){
            count++;
            ans++;
        }
        
      for(int i=1; i<nums.size();i++){
          
          if(nums[i]==0){
              count=0;
              continue;
          }
          
          if(nums[i-1]==nums[i]){
              count++;
          }else{
              count=1;
          }
          ans= max(ans, count);
      }
        return ans;
    }
};