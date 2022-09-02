class Solution {
public:
    int in[100010];
    int low[100010];
    vector<vector<int>> ans;
    int timer=0;
    void dfs(vector<vector<int>> &  adj, int src, int parent,vector<int> & visited){
        
        visited[src]=1;
        in[src]=timer;
        low[src]=timer;
        timer++;
        // cout<<src<<endl;
        for(auto  x: adj[src]){
            
            if(x == parent){
                 // cout<<"YES2\n";
                continue;
            }
            
            if(visited[x]==1){
                // cout<<"YES1\n";
                low[src]=min(low[src], in[x]);
                
            }else{
               
                // cout<<"YES\n";
               dfs(adj, x, src, visited);
                
               low[src]= min(low[src], low[x]);
                
              if(in[src]< low[x]){
                  ans.push_back({src, x});
              }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& ed) {
        
        vector<vector<int>> adj(n);
        timer=0;
        ans.clear();
        for(int i=0;i<=n;i++){
            
            in[i]=low[i]=1e9;
        }
        for(int i=0; i<ed.size();i++){
            
             adj[ed[i][0]].push_back(ed[i][1]);
            adj[ed[i][1]].push_back(ed[i][0]);
        }
        
//         for(auto  x: adj){
          
//             for( auto y : x){
                
//                 cout<<y<<" ";
//             }
//             cout<<endl;
//         }
        vector<int> visited(n,0);
        dfs(adj, 0, -1, visited);
        
        for(int i=0; i<n;i++){
            
            cout<<low[i]<<" ";
}
        cout<<endl;
        return ans;
    }
};