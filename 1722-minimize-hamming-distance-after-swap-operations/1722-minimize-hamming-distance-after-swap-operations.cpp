
class Solution {
public:
    void dfs(vector<vector<int>> & adj, vector<int> & visited, multiset<int> & s1,
             multiset<int> & s2, int src, vector<int> & s, vector<int> & t){
        
        
        s1.insert(s[src]);
        s2.insert(t[src]);
        visited[src]=1;
        for(auto  x: adj[src]){
            
            if(visited[x]==0){
                
                dfs(adj, visited, s1, s2, x, s, t);
            }
        }
        
        
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& arr) {
        
        
      int n=source.size(); 
      vector<vector<int>> adj(n);
        
        for(int i=0; i<arr.size();i++){
            
            adj[arr[i][0]].push_back(arr[i][1]);
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        
        
//         for(auto  x: adj){
            
//             for( auto  y : x){
                
//                 cout<<y<<" ";
//             }
            
//             cout<<endl;
//         }
        
        
        vector<int> visited(n,0);
        int ans=0;
        for(int i=0; i<n;i++){
            
            if(visited[i]==0){
                
                multiset<int> s1;
                multiset<int> s2;
                
                dfs(adj, visited, s1, s2, i, source, target);
                
                for(auto  x: s1){
                    
                    if(s2.count(x) !=0){
                        s2.erase(s2.find(x));
                    }else{
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};