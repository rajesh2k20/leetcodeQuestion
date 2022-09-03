int x[4]={0, 1, 0,-1};
int y[4]={1,0,-1, 0};
class Solution {
public:
    bool isvalid(int r, int c, int n, int m){
        
        if(r>=0 and c>=0 and r<n and c<m){
            
            
            return true;
        }else{
            
            return false;
        }
    }
    int helper(int r, int c, vector<vector<int>> & arr, vector<vector<int>> &  dp){
        
        int n= arr.size();
        int m=arr[0].size();
        int mod=1e9+7;
        
        if(dp[r][c] !=0){
            return dp[r][c];
        }
        dp[r][c]=1;
        
        for(int i=0; i<4;i++){
            
            int nr=  r+x[i];
            int nc=  c+y[i];
            
            if(isvalid(nr, nc,n,m )==true){
                
                if(arr[nr][nc]>arr[r][c]){
                    
                    dp[r][c]+= helper(nr, nc, arr, dp);
                    dp[r][c]%=mod;
                }
            }
        }
        
        return dp[r][c];
    }
    int countPaths(vector<vector<int>>& grid) {
        
         int n= grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>( m,0));
        int ans=0;
        int mod=1e9+7;
        for(int i=0; i<n;i++){
            
            for(int j=0; j<m;j++){
                
               if(dp[i][j]==0){
                   
                   ans+= helper(i,j,grid, dp);
                   ans%=mod;
               }else{
                   ans+=dp[i][j];
                   ans%=mod;
               } 
            }
        }
        
        return ans;
    }
};