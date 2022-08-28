class Solution {
public:
    int get(int r1, int r2, vector<vector<int>> & dp, int k){
        
        
        
   set<int> s;
    int m=dp[0].size();
    int ans=-1e9;
    s.insert(0);
      for(int i=1;i<m;i++){
          
          int sum= dp[r2][i]-dp[r1-1][i];
          
          int req= sum-k;
          
          // cout<<req<<endl;
          
          auto it= s.upper_bound(req);
          if(it==s.begin()){
              int currans= sum-(*it);
              // cout<<currans<<endl;
              if(currans<=k){
                 ans= max(currans, ans); 
              }
              s.insert(sum);
              continue;
          }else{
              int currans= sum-(*it);
              // cout<<currans<<endl;
              if(currans<=k){
                 ans= max(currans, ans); 
              }
              it--;
              
               currans= sum-(*it);
              // cout<<currans<<endl;
              if(currans<=k){
                 ans= max(currans, ans); 
              }
               s.insert(sum);
          }
      }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
      int n=matrix.size();
      int m=matrix[0].size();
        
      vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
     
     for(int i=1; i<=n;i++){
         
         for(int j=1; j<=m;j++){
             
           int r=i-1;
           int c= j-1;
            
            if(r==0 and c==0){
                dp[i][j]= matrix[r][c];
                
                
            }else if(r==0 ){
                
                dp[i][j]=dp[i][j-1]+matrix[r][c];
            }else if(c==0){
                
                dp[i][j]= dp[i-1][j]+matrix[r][c];
            }else{
                
                dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+matrix[r][c];
            }
             
         }
     }
        
     
      int ans=-1e9;  
     for(int i=1; i<=n;i++){
         
         for(int j=i; j<=n;j++){
             
           int currans= get(i,j, dp,k);
            // cout<<i<<" "<<j<<currans<<endl;
            if(ans<currans and currans <=k){
                ans=currans;
            }
         }
     }
        
        return ans;
        
    
        
        
    }
};