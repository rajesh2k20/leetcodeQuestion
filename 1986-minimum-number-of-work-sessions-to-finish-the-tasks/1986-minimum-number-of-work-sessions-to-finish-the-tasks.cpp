int dp[1<<15][150];
class Solution {
public:
    int helper(int mask, vector<int> & arr, int st, int sum){
        
        if(mask==0){
            
            return 1;
        }
        
        if(dp[mask][sum] !=-1){
            
            return dp[mask][sum];
        }
        
        
        int ans=1e9;
        for(int i=0; i<arr.size();i++){
            
            
            int bit=  (mask>>i ) & 1;
            
            if(bit==1){
                
                if(sum+ arr[i]<=st){
                    
                 ans= min(ans, helper(mask ^ (1<<i), arr, st, sum+arr[i]));
                  
                }else{
                    
                    ans= min(ans, 1+helper(mask ^ (1<<i), arr, st, arr[i]));
                }
            }
            
           
             
                
         }
           return dp[mask][sum]=ans;
        
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        
        int n=tasks.size();
        
        int mask= 1<<(n);
        mask--;
        
        // cout<<mask<<endl;
        
        memset(dp, -1, sizeof(dp));
        
        return helper(mask, tasks, sessionTime, 0);
        
        
    }
};