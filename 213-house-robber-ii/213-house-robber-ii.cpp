class Solution {
public:
    int helper(vector<int>  arr){
        
     
        int n=arr.size();
        
           if(n==0){
            return 0;
        }
        
        int dp[n];
        memset(dp, 0 , sizeof(dp));
        
        for(int i=0; i<n;i++){
            
            if(i==0){
                
                dp[i]=arr[i];
                continue;
            }
            
            if(i==1){
                dp[i]=max(arr[i], arr[i-1]);
                
                continue;
            }
            
            dp[i]= max(dp[i-1], dp[i-2]+arr[i]);
        }
        
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        
        if(nums.size()==1){
            
            return nums[0];
        }
        
        if(nums.size()==2){
            
            return max(nums[0], nums[1]);
        }
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        
        for(int i=1; i<n;i++){
            
           arr1.push_back(nums[i]); 
        }
        
        for(int i=2; i<n-1;i++){
            arr2.push_back(nums[i]);
        }
        cout<<arr1.size()<<" "<<arr2.size()<<endl;
        int ans1= helper(arr1);
        int ans2= nums[0]+helper(arr2);
        return max(ans1, ans2);
        
    }
};