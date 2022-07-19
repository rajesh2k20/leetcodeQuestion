class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      
      int sum=0;
      map<int, int> m;
      int ans=0;
        m[0]=1;
      for(int i=0; i<nums.size();i++){
          
          sum+=nums[i];
          if(m.count(sum-k)==1){
              ans+= m[sum-k];
          }
          
          m[sum]++;
      }
      return ans;
    }
};