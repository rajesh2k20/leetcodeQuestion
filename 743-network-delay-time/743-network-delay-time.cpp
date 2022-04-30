class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<pair<int, int>>> adj(n+1);
        
          for(auto  e : times){
              
              int u= e[0];
              int v= e[1];
              int w= e[2];
              
              adj[u].push_back({v,w});
          }
        vector<int> dp(n+1, 1e9);
        dp[k]=0;
        
        set<pair<int, int>> s;
        s.insert({0,k});
        while(s.size()>0){
            
         pair<int, int> curr= *(s.begin());
         int u= curr.second;
         s.erase(s.begin());
            
         for( auto  nb : adj[u]){
             
             int v= nb.first;
             int w= nb.second;
             
             if(dp[v]> dp[u]+w){
                 s.erase({dp[v], v});
                 dp[v]=dp[u]+w;
                 s.insert({dp[v], v});
             }
         }    
            
        }
        int ans=0;
        for(int i=1; i<=n;i++){
            
            if(dp[i]>=1e9){
                return -1;
            }
            ans= max(dp[i], ans);
        }
        return ans;
    }
};