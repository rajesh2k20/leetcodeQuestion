class Solution {
public:
    double helper(vector<vector<int>> & adj, int time, int target, int src, int parent){
        
        
        if(time==0  ){
            
            if(target==src){
                return 1;
            }else{
                return 0;
            }
        }
        double ans=0;
        double size=0;
        if(src==1){
            size=adj[src].size();
        }else{
            size=adj[src].size()-1;
        }
        
        if(size==0){
            ans+= helper(adj, time-1, target, src, parent);
        }
        for(auto  x: adj[src]){
            
            if(x == parent){
                continue;
            }
            
            ans+= (1.0/(size))*helper(adj, time-1, target, x, src);
            
            
        }
        
        
        
        
        
        return ans;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        vector<vector<int>> adj(n+1);
        
        for(int i=0; i<edges.size();i++){
            
             // adj[edges[i][0]]=edges[i][1];
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        return helper(adj,t, target, 1,-1);
        
    }
};