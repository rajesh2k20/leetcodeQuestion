int dp[1001][1001][3];
class Solution {
public:
    int helper(int index, int last, int sign,vector<int> & arr){
        
        if(index==arr.size()){
            return 0;
        }
        
        
        if(dp[index][last][sign] !=-1){
            
            return dp[index][last][sign];
        }
        
        if(sign==0){
            
            if(arr[index]>last){
                int ans1= 1+helper(index+1, arr[index], 1, arr);
                int ans2= helper(index+1, last, 0, arr);
                return dp[index][last][sign]=max(ans1, ans2);
            }else{
                
                return dp[index][last][sign]=helper(index+1, last, 0, arr);
            }
            
        }else if(sign==1){
            
           if(arr[index]<last){
                int ans1= 1+helper(index+1, arr[index], 0, arr);
                int ans2= helper(index+1, last, 1, arr);
                return dp[index][last][sign]=max(ans1, ans2);
            }else{
                
                return dp[index][last][sign]=helper(index+1, last, 1, arr);
            } 
            
        }else{
            
            int ans1= helper(index+1, last, sign, arr);
            
            if(arr[index]>last){
                
             
              int ans2= 1+ helper(index+1, arr[index], 1,arr);
                
              return dp[index][last][sign]=max(ans1, ans2);
                
            }else if(arr[index]<last){
                
                int ans3= 1+helper(index+1, arr[index], 0, arr);
                
                return dp[index][last][sign]=max(ans1, ans3);
                
            }else{
                
                return dp[index][last][sign]=ans1;
            }
            
            
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        
        
        memset(dp, -1, sizeof(dp));
        
        return 1+helper(1, nums[0], 2, nums);
        
    }
};