class Solution {
public:
     int x[4]={0,1,0,-1};
    int y[4]={1,0,-1,0};
    bool isvalid(int nr, int nc, int n, int m){
        
        if(nr>=0 and nc>=0 and nr<n and nc<m ){
            return true;
        }
        
        return false;
    }
    bool check(int index, vector<vector<int>> &  cells, int n, int m){
        
        vector<vector<int>> arr(n, vector<int>(m,0));
        
        for(int i=0; i<=index;i++){
            
            arr[cells[i][0]-1][cells[i][1]-1]=1;
        }
        
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<m;i++){
            
            if(arr[0][i]==0){
                q.push({0,i});
            }
        }
        
        
        
        while(q.size()>0){
            
            pair<int, int> curr=q.front();
            
            q.pop();
            
            if(curr.first==n-1){
                return true;
            }
            
            for(int i=0; i<4;i++){
                
                int nr= curr.first+x[i];
                int nc= curr.second+ y[i];
                
                if(isvalid(nr, nc, n,m)==true){
                    
                    if(arr[nr][nc]==0){
                        
                        q.push({nr,nc});
                        arr[nr][nc]=1;
                    }
                    
                }
            }
        }
        
        return false;
        
}
int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int low=0;
        int high=cells.size()-1;
        int ans=0;
        while(low<=high){
            
            int mid= (low+high)/2;
            
            if(check(mid, cells, row, col)==true){
                
                 ans=mid+1;
                low=mid+1;  
            }else{
                high=mid-1;
            }
        }
        
        return ans;
        
        
    }
};