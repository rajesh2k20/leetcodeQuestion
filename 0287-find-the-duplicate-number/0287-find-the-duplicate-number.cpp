class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        
     int fast=nums[0];
      int slow=nums[0];
        
     while(true){
         
         fast=nums[nums[fast]];
         slow=nums[slow];
         
         if(fast==slow){
             break;
         }
     }
        
    cout<<slow<<endl;
        
    slow=nums[0];
        
    while(slow !=fast){
        
       slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
     
        
    }
};