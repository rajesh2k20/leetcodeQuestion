class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
     
     int n=nums.size();
     int dp1[n];
     int sum=0;
     memset(dp1, 0, sizeof(dp1));
     for(int i=0; i<n;i++){
         // dp1[i]=-1e9;
         if(i<firstLen){
           sum+= nums[i];
            dp1[i]=-1e9;
         }else{
             
             if(i<=1){
                dp1[i-1]= sum; 
             }else{
                 dp1[i-1]= max(dp1[i-2], sum );
             }
             // cout<<dp1[i-1]<<" ";
             sum+=nums[i];
             sum-=nums[i-firstLen];
             
         }
     }
     // cout<<endl;
      dp1[n-1]= max(dp1[n-2], sum);
      sum=0;
     int dp2[n];
      for(int i=0; i<n;i++){
         dp2[i]=-1e9;
         if(i<secondLen){
           sum+= nums[i];
            
         }else{
               if(i==1){
                dp2[i-1]= sum; 
             }else{
                 dp2[i-1]= max(dp2[i-2], sum );
             }
             sum+=nums[i];
             sum-=nums[i-secondLen];
            
         }
     }
    dp2[n-1]= max(dp2[n-2], sum);
     reverse(nums.begin(), nums.end());
     sum=0;
     int dp3[n];
    
     for(int i=0; i<n;i++){
         dp3[i]=-1e9;
         if(i<firstLen){
           sum+= nums[i];
            
         }else{
             if(i==1){
                dp3[i-1]= sum; 
             }else{
                 dp3[i-1]= max(dp3[i-2], sum );
             }
             sum+=nums[i];
             sum-=nums[i-firstLen];
             
         }
     }
      dp3[n-1]= max(dp3[n-2], sum);  
     sum=0;
     int dp4[n];
    
     for(int i=0; i<n;i++){
         dp4[i]=-1e9;
         if(i<secondLen){
           sum+= nums[i];
            
         }else{
             if(i==1){
                dp4[i-1]= sum; 
             }else{
                 dp4[i-1]= max(dp4[i-2], sum );
             }
             sum+=nums[i];
             sum-=nums[i-secondLen];
             
         }
     }
    dp4[n-1]= max(dp4[n-2], sum);
     reverse(dp3, dp3+n);
     reverse(dp4, dp4+n);
     int ans=0;
    for(int i=0; i<n-1;i++){
        
        ans= max( {dp1[i]+dp4[i+1], dp2[i]+dp3[i+1], ans});
      // cout<<dp1[i]+dp4[i]<<" "<<dp2[i]+dp3[i]<<endl;
    }
        
    return ans;
     
        
     
    
    
    }
};