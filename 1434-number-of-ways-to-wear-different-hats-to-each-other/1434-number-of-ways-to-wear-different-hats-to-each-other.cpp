int dp[41][1<<11];
class Solution {
public:
    
    int helper(int index, vector<vector<int>> & arr, int mask){
        
        if(index==41){
            
            if(mask==0){
                
               return 1;  
            }else{
                return 0;
            }
        }
        if(dp[index][mask]  != -1){
            
            return dp[index][mask];
        }
        int mod=1e9+7;
        int ans=0;
        int ans1= helper(index+1, arr, mask);
        
        ans+=ans1;
        ans%=mod;
        
        for(int i=0; i<arr.size();i++){
            
            for(int j=0; j<arr[i].size();j++){
                
                if(arr[i][j]==index){
                    
                    if((mask >> i ) & 1 ==1){
                        int ans2= helper(index+1, arr, mask ^ (1<<i));
                        ans+=ans2;
                        ans%=mod;
                    }
                }
            }
        }
        
        return dp[index][mask]=ans;
    }
    int numberWays(vector<vector<int>>& hats) {
        
        int n=hats.size();
        int mask= 1<<(n);
        mask--;
        
        memset(dp, -1, sizeof(dp));
        
        int ans= helper(1,hats, mask);
        return ans;
        
        
        
    }
};