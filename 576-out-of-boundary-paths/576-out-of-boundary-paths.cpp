class Solution {
public:      
            //R,D,L ,U
    int x[4]={0,1,0,-1};
    int y[4]={1,0,-1,0};
    int mod=1e9+7;
    int dp[51][51][51];
    int helper(int n, int m, int moves, int r, int c){
        
        if(r<0 || c<0 || r>=n || c>=m){
            return 1;
        }
        
        if(moves==0){
            return 0;
        }
        
        if(dp[r][c][moves] !=-1){
            
            return dp[r][c][moves];
        }
        
        int ans=0;
        
        for(int i=0; i<4;i++){
            
            int nr=r+x[i];
            int nc= c+y[i];
            
            ans+= helper(n,m, moves-1, nr, nc);
            ans%=mod;
        }
        return  dp[r][c][moves]=ans;
        
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return helper(m,n,maxMove, startRow, startColumn );
        
    }
};