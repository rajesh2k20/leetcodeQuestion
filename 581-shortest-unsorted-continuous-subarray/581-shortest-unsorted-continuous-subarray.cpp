class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     
     vector<int> arr(nums.begin(), nums.end());
      sort(arr.begin(), arr.end());
      int index1=-1;
      int index2=-1;
      if(arr==nums){
          return 0;
      }
      for(int i=0; i<nums.size();i++){
          
          if(arr[i] != nums[i]){
              index1=i;
              break;
          }
      }
      for(int i=nums.size()-1 ;i>=0; i--){
          
          if(arr[i]!=nums[i]){
              index2=i;
              break;
          }
      }
       // cout<<index1<<" "<<index2<<endl; 
      return index2-index1+1;
      
     
    }
};