class Solution {
public:
    
   
    
    int helperfunction(vector<vector<int>> & dp, int r1, int c1, int n, int m, int target){
        
      
     int ans=0;
    for(int i=r1; i<=n;i++){
        
        for(int j=c1; j<=m;j++){
            
            int currsum=  dp[i][j]-dp[i][c1-1]-dp[r1-1][j]+dp[r1-1][c1-1];
            
            if(currsum==target){
                ans++;
            }
        } 
      }
        
        return ans;
         
    }
    int numSubmatrixSumTarget(vector<vector<int>>& arr, int target) {
        
      int n= arr.size();
      int m= arr[0].size();
     
     vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
    
        
     for(int i=1; i<=n;i++)
     {
         
         for(int j=1; j<=m;j++)
         {
            
             
             
            dp[i][j]= arr[i-1][j-1]+ dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
             
             
         }
     }
        
     int ans=0;
        
      for(int i=1; i<=n;i++){
          
          
          for(int j=1; j<=m;j++){
              
              ans+= helperfunction(dp,i,j,n,m,target);
          }
      }
        
        
        return ans;
        
        
    
        
        
        
        
        
    }
};