class Solution {
public:
    vector<pair<int, int>> dp1;
    void dfs(int parent, int src, vector<vector<int>> & adj){
        
       int countnode=1;
       int dis=0;
        for(auto  x: adj[src]){
            
            if(x==parent){
                
                continue;
            }
            
            dfs(src,x, adj);
            
            
        }
        
        for(auto  x: adj[src]){
            
            if(x==parent){
                continue;
            }
            
            dis+= dp1[x].first+ dp1[x].second;
            countnode+=dp1[x].second;
            
        }
        
        dp1[src].first=dis;
        dp1[src].second=countnode;
        
        
        
        
        
    }
    
    
    void dfs2(vector<vector<int>> & adj, int src, int parent, vector<int> & ans, int n){
        
        
        
        if(parent==-1){
            
            ans[src]=dp1[src].first;
            
        }else{
            
          // int subnodeOfRoot= dp1[root].second;
          int subnodeOfcurrNode= dp1[src].second;
          int distOfroot= ans[parent];
          // int disofnode= dp1[src].first;
            
          ans[src]= (n- subnodeOfcurrNode)+ distOfroot- subnodeOfcurrNode;
            
        }
        
        for(auto  x: adj[src]){
            
            if(x==parent){
                continue;
            }
            dfs2(adj, x, src, ans, n);
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
     
        dp1.resize(n+10,{0,0});
        
        vector<vector<int>> adj(n+1);
        
         
        
        for(int i=0; i<edges.size();i++){
            
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            
            adj[v].push_back(u);
        }
        
//         for(int i=0; i<n;i++){
            
            
//             for(auto  x: adj[i]){
                
//                 cout<<x<<" ";
//             }
            
//             cout<<endl;
//         }
        
        
        
        
        dfs(-1, 0, adj);
        
//         for(int i=0; i<n;i++){
            
//             cout<<dp1[i].first<<" "<<dp1[i].second<<endl;
//         }
        
        vector<int> ans(n);
        
        dfs2(adj, 0, -1, ans,n);
        
        
        return ans;
        
        
        
        
        
        
        
        
       
        
        
    }
};