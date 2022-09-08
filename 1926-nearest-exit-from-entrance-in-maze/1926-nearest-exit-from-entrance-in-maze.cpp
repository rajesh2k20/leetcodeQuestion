class Solution {
public:
    
    int x[4]={0,1,0,-1};
    int y[4]={1,0,-1,0};
    bool isvalid(int r, int c, int n, int m){
        
        if(r>=0 and c>=0 and r<n and c<m){
            return true;
        }
        
        return false;
    }
    
    bool isequal(int r, int c, int er,int ec){
        
        if(r==er and c==ec){
            return true;   
        }else{
            return false;
        }
        
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
      
     queue<pair<int, pair<int, int>>> q;
     int n=maze.size();
     int m=maze[0].size();
      int er= entrance[0];
      int ec=entrance[1];
        q.push({er,{ec,0}});
        vector<vector<int>> visited(n, vector<int>(m,0));
        visited[er][ec]=1;
        while(q.size()>0){

         pair<int, pair<int, int>> curr= q.front();
            
         q.pop();
            
         
        int r= curr.first;
        int c= curr.second.first;
        int step=curr.second.second;
        
            // cout<<r<<" "<<c<<endl;
            
        if((r==0 || r== n-1 || c==0 || c==m-1 )and isequal(r, c, er, ec)==false ){
            
            return step;
        }
            
         
         for(int i=0; i<4;i++){
             
             int nr= r+x[i];
             int nc= c+y[i];
             
             if(isvalid(nr, nc, n, m)==true){
                 
                 if(visited[nr][nc]==0 and maze[nr][nc]=='.'){
                     
                     q.push({nr,{nc, step+1}});
                     visited[nr][nc]=1;
                 }
             }
             
         }
        
            
           
            
        
        }
        
        return -1;
    }
};