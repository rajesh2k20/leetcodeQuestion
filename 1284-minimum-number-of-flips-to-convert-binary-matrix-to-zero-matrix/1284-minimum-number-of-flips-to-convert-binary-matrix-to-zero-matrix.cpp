class Solution {
public:
    vector<vector<int>> get(vector<vector<int>> & arr, int r, int c, int n, int m){
        
        
        vector<vector<int>> d(n, vector<int>(m,0));
        
        
        for(int i=0; i<n;i++){
            
            for(int j=0; j<m;j++){
                
                int val1= abs(r-i);
                int val2=abs(c-j);
                
                if(val1+val2==0 || val1+val2==1){
                    
                    d[i][j]= 1^arr[i][j];
                }else{
                    d[i][j]=arr[i][j];
                }
            }
        }
        
//         for(int i=0; i<n;i++){
            
//             for(int j=0; j<m;j++){
                
//                 cout<<d[i][j]<<" ";
//             }
            
//             cout<<endl;
//         }
        
        return d;
        
        
    }
    
    bool isvalid(vector<vector<int>> & arr,  int n, int m){
        
       
        
        for(int i=0; i<n;i++){
            
            for(int j=0; j<m;j++){
                
                if(arr[i][j]==1){
                    return false;
                }
            }
        }
        
        return true;
    }
    int  bfs(vector<vector<int>>  arr, set<vector<vector<int>>> & s){
        
         int n=arr.size();
        int m=arr[0].size();
        queue<pair<vector<vector<int>>, int>> q;
        
        q.push({arr, 0});
        
        s.insert(arr);
        
        while(q.size()>0){
            
            pair<vector<vector<int>>, int> curr=q.front();
            q.pop();
            
            
            if(isvalid(curr.first, n,m)==true){
                return curr.second;
            }
            
            for(int i=0;i<n;i++){
                
                for(int j=0; j<m;j++){
                    
                    vector<vector<int>> d= get(curr.first,i,j,n,m);
                    
                    if(s.count(d)==1){
                        continue;
                    }
                    
                    s.insert(d);
                    q.push({d, curr.second+1});
                }
            }
        }
        
        return -1;
    }
    void helper(int & ans, vector<vector<int>>  arr, set<vector<vector<int>>> & s, int currans){
        
        int n=arr.size();
        int m=arr[0].size();
        if(isvalid(arr,n,m)==true){
            cout<<currans<<endl;
            ans= min(ans, currans);
            return ;
        }
        
        if(s.count(arr)==1){
            return ;
        }else{
            s.insert(arr);
        }
        
        
        for(int i=0; i<n;i++){
            
            for(int j=0; j<m;j++){
                
                
                vector<vector<int>> d= get(arr,i,j,n,m);
                
                helper(ans,d,s,currans+1);
                
                
            }
        }
        
        
        
    
        
    }
    int minFlips(vector<vector<int>>& mat) {
     
        // int ans=1e9;
        set<vector<vector<int>>> s;
        // helper(ans,mat,s, 0);
        
     return   bfs(mat, s);
        
    }
};