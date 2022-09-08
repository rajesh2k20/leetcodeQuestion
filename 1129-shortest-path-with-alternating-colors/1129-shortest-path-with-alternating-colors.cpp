class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        
        
     vector<vector<pair<int, char>>> adj(n);
        
        for(int i=0; i<r.size();i++){
            
            int u= r[i][0];
            int v= r[i][1];
            adj[u].push_back({v, 'R'});
        }
        
        for(int i=0; i<b.size();i++){
            
            int u= b[i][0];
            int v= b[i][1];
            adj[u].push_back({v, 'B'});
        }
        
        
        queue<pair<int, char>> q;
        
        q.push({0, 'W'});
        
        set<pair<int, char>> s;
        
        s.insert({0,'W'});
        s.insert({0, 'R'});
        s.insert({0, 'B'});
        vector<vector<int>> ans(n,vector<int>(2,1e9));
        ans[0][0]=0;
        ans[0][1]=0;
        while(q.size()>0){

            
            pair<int, char> curr= q.front();
            
            q.pop();
            
            int src= curr.first;
            char color= curr.second;
            
            for(auto  x: adj[src]){
                
                if(color==x.second){
                    
                    continue;
                }
                
                if(s.count({x.first, x.second})==0){
                    
                    q.push({x.first, x.second});
                    s.insert({x.first, x.second});
                    if(x.second=='R'){
                     ans[x.first][0]= 1+ans[src][1];   
                    }else{
                        ans[x.first][1]=1+ans[src][0];
                    }
                }
                
            }
            
        }
        
        
        vector<int> fans(n,-1);
        
        for(int i=0; i<n;i++){
            
            fans[i]= min(ans[i][0], ans[i][1]);
        }
        
        for(int i=0; i<n;i++){
            
            if(fans[i]>=1e9){
                fans[i]=-1;
            }
        }
        
        return fans;
        
        
    }
};