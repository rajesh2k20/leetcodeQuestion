class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      
       vector<int> dp(n+1,1e9);
       dp[k]=0;
       for(int i=1; i<n;i++){
          
           for(auto e : times ){
               int u= e[0];
               int v=e[1];
               int w=e[2];
               dp[v]= min(dp[v], dp[u]+w);
           }
       }
      int ans=0;
     for(int i=1; i<=n;i++){
         
         if(dp[i]>=1e9){
             return -1;
         }
         ans=max(dp[i], ans);
     }
     return ans;
    }
};