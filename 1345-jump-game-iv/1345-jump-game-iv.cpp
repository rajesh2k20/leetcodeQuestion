class Solution {
public:
    int minJumps(vector<int>& arr) {
        
      map<int, vector<int>> m;
        
        
      for(int i=0; i<arr.size();i++){
          
          m[arr[i]].push_back(i);
      }
        
    int n= arr.size();
        
      queue<pair<int, int>> q;
        
        q.push({0,0});
        
        vector<int> visited(n,0);
        
        visited[0]=1;
        
        while(q.size()>0){
            
           pair<int, int> curr= q.front();
            
           q.pop();
            
            if(curr.first==arr.size()-1){
                
                return  curr.second;
            }
            
            
            int val= arr[curr.first];
            
            
            for(auto  x:  m[val]){
                
                if(visited[x]==0){
                   
                    q.push({x, curr.second+1});
                    visited[x]=1;
                }
            }
            
            m.erase(val);
            
            if(curr.first-1>=0){
                
                if(visited[curr.first-1]==0){
                    
                    q.push({curr.first-1, curr.second+1});
                    
                    visited[curr.first-1]=1;
                }
            }
            
            if(curr.first+1<arr.size()){
                
                if(visited[curr.first+1]==0){
                    
                    q.push({curr.first+1, curr.second+1});
                    
                    visited[curr.first+1]=1;
                }
            }
            
            
            
            
            
            
        }
        
        return -1;
        
    }
};