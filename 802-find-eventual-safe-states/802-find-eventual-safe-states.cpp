class Solution {
public:
    int dfs(vector<vector<int>> & adj, map<int, int> & m, int src,vector<int> & visited){
        
        
        if(visited[src]==0){
            visited[src]=1;
        }
        
        if(m.count(src)==1){
            return m[src];
        }
        
        int ans=1;
        for(auto  x : adj[src]){
            
            if(visited[x]==0){
               
             ans &= dfs(adj, m, x, visited);
            }else if(visited[x]==1){
                return m[src]=0;
            }else{
                
               ans &= dfs(adj, m, x, visited);
            }
        }
        visited[src]=2;
        return m[src]=ans;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        
      map<int, int> m;
        
     int n=adj.size();
     vector<int> visited(n,0);   
        vector<int> arr;
      for(int i=0; i<n;i++){
           
          
          int ans= dfs(adj, m, i, visited);
          // cout<<i<<" "<<ans<<endl;
          
          if(ans==1){
              arr.push_back(i);
          }
          
      }
        
        return arr;
    }
};