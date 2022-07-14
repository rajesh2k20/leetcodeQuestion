class Solution {
public:
    void sortColors(vector<int>& nums) {
        
      int i=-1;
      int j=nums.size();
      int k=0;
        
    while(k<j){
        
        if(nums[k]==0){
            i++;
            swap(nums[i], nums[k]);
            k++;
        }else if(nums[k]==1){
            k++;
        }else{
            j--;
            swap(nums[j], nums[k]);
            
        }
    }
        
    }
};