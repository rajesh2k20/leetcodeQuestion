class Solution {
public:
    void bfs(vector<vector<int>> & adj, vector<int> & dp, int src){

     queue<int> q;
        
        q.push(0);
        
        vector<int> visited(adj.size(),0);
        while(q.size()>0){
            
            int curr= q.front();
            q.pop();
            
            for(auto  x: adj[curr]){
                
                if(visited[x]==0){
                    
                    dp[x]=dp[curr]+1;
                    q.push(x);
                    visited[x]=1;
                }
            }
        }
    
    }
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& arr) {
      
    int n=arr.size();
        
      vector<vector<int>> adj(n);
        
        
        for(int i=0;i<edges.size();i++){
            
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>dp(n,0);
        
        bfs(adj, dp,0);
        
        
        int ans=-1;
        
        for(int i=1;i<n;i++){
            
            int dis=2*dp[i];
            int val= (dis-1)/arr[i];
            int time= dis- ((dis-1)/arr[i])*arr[i];
            if(val>0){
                ans= max(ans, 2*dis-time);
            }else{
                ans= max(dis, ans);
            }
        }
        
        return ans+1;
        
        
    }
};