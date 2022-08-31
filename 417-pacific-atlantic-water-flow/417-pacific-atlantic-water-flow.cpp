class Solution {
public:
    int x[4]={0,1,0,-1};
    int y[4]={1,0,-1,0};
    // map<pair<int, int>, pair<int,int>> m;
    
        
     bool isvalid(int r, int c,int n, int m){
         
         if(r>=0 and c>=0 and r<n and c<m){
             return true;
         }else{
             return false;
         }
     } 
    void bfsA(vector<vector<int>> & arr, vector<vector<pair<int, int>>> & visited){
        
        int n=arr.size();
        int m=arr[0].size();
        queue<pair<int, pair<int, int>>> q;
        
        for(int i=0; i<m;i++){
            
            q.push({n,{i,-1e9}});
        }
        
        for(int i=0; i<n;i++){
            
            q.push({i,{m,-1e9}});
        }
        
        
        while(q.size()>0){
            
            
            pair<int, pair<int,int>> p= q.front();
            q.pop();
            
            if(isvalid(p.first, p.second.first, n,m)==true){
                
                visited[p.first][p.second.first].second=1;
            }
            
            for(int i=0; i<4;i++){
                
                int nr= p.first+x[i];
                int nc= p.second.first+y[i];
                int weight=p.second.second;
                
                if(isvalid(nr,nc,n,m)==true){
                    
                    if(visited[nr][nc].second==0 and arr[nr][nc]>=weight){
                        
                       q.push({nr,{nc, arr[nr][nc]}});
                    }
                }
            }
        }
        
        
        
        
    }
    void bfsP(vector<vector<int>> & arr, vector<vector<pair<int, int>>> & visited){
        
        int n=arr.size();
        int m=arr[0].size();
        
          queue<pair<int, pair<int, int>>> q;
        
        for(int i=0; i<m;i++){
            
            q.push({-1,{i,-1e9}});
        }
        
        for(int i=0; i<n;i++){
            
            q.push({i,{-1, -1e9}});
        }
        
        
        while(q.size()>0){
            
            
             pair<int, pair<int,int>> p= q.front();
            q.pop();
            
            if(isvalid(p.first, p.second.first, n,m)==true){
                
                visited[p.first][p.second.first].first=1;
            }
            
            for(int i=0; i<4;i++){
                
                int nr= p.first+x[i];
                int nc= p.second.first+y[i];
                int weight=p.second.second;
                
                if(isvalid(nr,nc,n,m)==true){
                    
                    if(visited[nr][nc].first==0 and arr[nr][nc]>=weight){
                        
                       q.push({nr,{nc, arr[nr][nc]}});
                    }
                }
            }
        }
        
        
        
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        
        
        
        vector<vector<int>> ans;
        vector<vector<pair<int, int>>> visited(arr.size(), vector<pair<int,int>>(arr[0].size()));
        
        bfsP(arr, visited);
        bfsA(arr, visited);
        
        int n=arr.size();
        int m=arr[0].size();
        
        for(int i=0; i<n;i++){
            
            for(int j=0; j<m;j++){
                
                if(visited[i][j].first==1 and visited[i][j].second==1){
                    
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
    }
};