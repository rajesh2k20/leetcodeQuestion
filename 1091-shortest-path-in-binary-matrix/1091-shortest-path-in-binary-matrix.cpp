class Solution {
public:
    bool isvalid(int nr, int nc, int n){
        
        if(nr>=0 and nc>=0 and nr<n and nc<n){
            return true;
        }
        
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
     
    int n= grid.size();
    vector<vector<int>> visited(n, vector<int>(n,0));
    queue<pair<int, pair<int, int>>> q;
      if(grid[0][0]==0){
          q.push({1,{0,0}});
      }
      int x[8]={0,1,1,1,0,-1,-1,-1};
      int y[8]={1,1,0,-1,-1,-1,0,1};
      while(q.size()>0){
          
          pair<int, pair<int, int>> curr= q.front();
          q.pop();
          int dis= curr.first;
          int r= curr.second.first;
          int c= curr.second.second;
          if(r==n-1 and c==n-1){
              return dis;
          }
          for(int i=0; i<8;i++){
              
              int nr= r+x[i];
              int nc= c+y[i];
              
              if(isvalid(nr,nc, n)==true){
                  
                  if(visited[nr][nc]==0 and grid[nr][nc]==0){
                      q.push({dis+1, {nr, nc}});
                      visited[nr][nc]=1;
                  }
              }
          }
          
          
      }
        return -1;
    }
};