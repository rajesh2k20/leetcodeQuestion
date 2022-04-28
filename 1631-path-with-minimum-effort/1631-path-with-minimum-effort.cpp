class Solution {
public:
    bool isvalid(int nx, int ny, int n, int m){
        
        if(nx>=0 and ny>=0 and nx<n and ny<m){
            
            return true;
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& arr) {
       
      int n=arr.size();
      int m= arr[0].size();
      if(n==1 and m==1){
          return 0;
      }
      int dp[n][m];
      for(int i=0; i<n;i++){
         for(int j=0; j<m;j++){
           
           dp[i][j]=1e9;
            
         }
        
     }
      dp[0][0]=0;
      set<pair<int, pair<int, int>>> s;
      s.insert({0,{0,0}});
      int x[4]={0,1,0,-1};
      int y[4]={1,0,-1,0};
      while(s.size()>0){
          
          pair< int, pair<int, int>> curr= *s.begin();
          int wtill=curr.first;
          int x1= curr.second.first;
          int y1= curr.second.second;
          s.erase(s.begin());
          
          for(int i=0; i<4;i++){
              int nx= x[i]+x1;
              int ny= y[i]+y1;
              if(isvalid(nx,ny,n,m)==true){
                 
                int w= max(wtill, abs(arr[nx][ny]- arr[x1][y1]));
                if(dp[nx][ny]> w){
                    s.erase({dp[nx][ny],{nx,ny}});
                    dp[nx][ny]=w;
                     s.insert({dp[nx][ny],{nx,ny}});
                }
                
                 
              }
          }
          
          
          
      }
    
    
     return dp[n-1][m-1];
    }
};