class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      int n=nums.size();
     vector<int> suffixmin(n);
      suffixmin[n-1]=nums[n-1];
     for(int i=n-2; i>=0;i--){
       
        suffixmin[i]= min(suffixmin[i+1], nums[i]);
     }
     int index1=-1;
     
        
      for(int i=0; i<n;i++){
          
          if(i==0){
              
              if(suffixmin[i]!=nums[i]){
                  index1=i;
                  break;
              }
              continue;
          }
          
          if(nums[i-1]<=nums[i] ){
              
             if(suffixmin[i]!=nums[i]){
                 index1=i;
                 break;
             }
          }else{
              index1=i;
              break ;
          }
      }
     if(index1==-1){
         return 0;
     }
     int index2=-1;
     vector<int> prefixmax(n);
     prefixmax[0]=nums[0];
     for(int i=1; i<n;i++){
         
         prefixmax[i]= max(prefixmax[i-1], nums[i]);
     }
     
     for(int i=n-1; i>=0; i--){
         
         if(i==n-1){
            
            if(prefixmax[i] != nums[i]){
                index2=i;
                break;
            }
            continue;
             
         }
         
         if(nums[i]<=nums[i+1]){
             
             if(prefixmax[i] != nums[i]){
                index2=i;
                break;
            }
              
         }else{
             
             index2=i;
             break;
         }
     }
      cout<<index1<<" "<<index2<<endl; 
     return index2-index1+1;
        
        
        
        
    }
};