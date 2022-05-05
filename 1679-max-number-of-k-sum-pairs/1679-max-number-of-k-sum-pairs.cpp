class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       
     int i=0;
     int j=nums.size()-1;
     sort(nums.begin(), nums.end());
     int ans=0;
     while(i<j){
         
        if(nums[i]+nums[j]==k){
            ans++;
            i++;
            j--;
        }else if(nums[i]+nums[j]>k){
            
            j--;
        }else{
            i++;
        }  
     }
      return ans;
    }
};