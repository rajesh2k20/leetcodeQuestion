class Solution {
public:
    int x[4]={0,1,0,-1};
    int y[4]={1,0,-1,0};
    bool isvalid(vector<vector<int>>& visited, int n,int m, int r, int c){
        
        if(r>=0 and c>=0 and r<n and c<m and visited[r][c]==0){
            return true;
        }
        return false;
    }
    bool check(vector<vector<int>>& arr, int mid){
        int n=arr.size();
        int m=arr[0].size();
        queue<pair<int, int>> q;
        
        vector<vector<int>> visited(n, vector<int>(m,0));
        q.push({0,0});
        while(q.size()>0){
            
            pair<int, int> p= q.front();
            
            q.pop();
            
            if(p.first==n-1 and p.second==n-1){
                return true;
            }
            
            for(int i=0; i<4;i++){
                
                int nr= x[i]+p.first;
                int nc=y[i]+p.second;
                
                if(isvalid(visited,n,n, nr,nc)==true and arr[nr][nc]<=mid){
                    
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                    
                }
                
            }
        }
        
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        
        int low=grid[0][0];
        
        int high=1e5;
        
        int ans=0;
        
        while(low<=high){
            
            int mid= (low+high)/2;
            
            // cout<<mid<<endl;
            
            if(check(grid, mid)==true){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return ans;
        
    }
};