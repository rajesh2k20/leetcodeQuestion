class Solution {
public:
    int x[4]={0,1,0,-1};
    int y[4]={1,0,-1,0};
    bool isvalid(int r, int c, int n, int m){
        
        
        if(r>=0 and c>=0 and r<n and c<m){
            return true;
        }else{
            return false;
        }
    }
    int helper(vector<vector<int>> & arr, vector<vector<int>> & ans, int r, int c, int parentval){
        
        if(arr[r][c]<=parentval){
            return 0;
        }
        if(ans[r][c] !=-1){
            return ans[r][c];
        }
        
        int fans=0;
        for(int i=0; i<4;i++){
            
            int nr= r+x[i];
            int nc= c+y[i];
            
            if(isvalid(nr, nc, arr.size(), arr[0].size())==true){
                
               int currans= helper(arr, ans, nr, nc, arr[r][c]);
                fans=max(fans, currans);
            }
        }
        
      return  ans[r][c]=fans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m,-1));
        
        for(int i=0; i<n;i++){
            
            for(int j=0; j<m;j++){
                
                if(ans[i][j]==-1){
                    
                    helper(matrix,ans,i,j,-1);
                }
            }
        }
        
        int maxans=0;
   
        for(int i=0; i<n;i++){
            
            for(int j=0; j<m;j++){
                
                maxans= max(maxans, ans[i][j]);
                // // cout<<ans[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return maxans;
        
    }
};