class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        
      int maxval= nums.size();
    
    
     for(int i=0; i<nums.size();i++){
         
         int index= nums[i]%maxval;
         index--;
         nums[index]+=maxval;
     }
        
     for(int i=0; i<nums.size();i++){
         
         if(nums[i]/maxval>=2){
             return i+1;
         }
     }
        
    
      return 0;
     
        
    }
};