class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      
    
      int index1=-1;
       int index2=-1;
      int size= nums.size();
     
        for(int i=size-2;i>=0;i--){
            
            if(nums[i]<nums[i+1]){
                index1=i;
                break;
            }
        }
        // cout<<index1<<endl;
        if(index1==-1){
            
            return sort(nums.begin(), nums.end());
        }
        
        for(int i=size-1; i>index1;i--){
            
            if(nums[index1]<nums[i]){
                index2= i;
                break;
            }
            
        }
        
        // cout<<index1<<" "<<index2<<endl;
        
        swap(nums[index1],nums[index2]);
        
        reverse(nums.begin()+index1+1, nums.end());
        
        
        
       
    }
};