int dp2[1<<12][12];
int dp1[13][13];
class Solution {
public:
    void pairdistance(vector<vector<int>> & graph){
        
       int n=graph.size();
        
        
        
        for(int i=0; i<n;i++){
            
            for(int j=0; j<n;j++){
                
                if(i==j){
                    dp1[i][i]=0;
                }else{
                    dp1[i][j]=1e9;
                }
            }
        }
        
        for(int i=0; i<n;i++){
            
            for(int j=0; j<graph[i].size();j++){

               int u= i;
               int v= graph[i][j];
                
                dp1[u][v]=1;
                
            }
        }
        
        for(int k=0; k<n;k++){
            
            for(int i=0; i<n;i++){
              
                
                for(int j=0; j<n;j++){

                    
                    if(dp1[i][k]<1e9 and dp1[k][j]<1e9){
                        
                        dp1[i][j]= min(dp1[i][j], dp1[i][k]+dp1[k][j]);
                    }

                }
            }
        }
        
        
        
    }
    int helper(int mask, int src){
        
        
        if(mask==0){
          return 0;
        }
        
        
        if(src !=-1 and dp2[mask][src] !=-1){
           return dp2[mask][src];
        }
        
        int ans=1e9;
        for(int i=0; i<12;i++){
            
            
            int bit= (mask>>i) & (1);
            
            if(bit==1){
                
               if(src==-1){
                   
                  int currans= helper(mask^ (1<<i), i);
                    ans= min(ans, currans);
                   
               }else{
                   
                  int currans= dp1[src][i]+ helper(mask ^(1<<i), i); 
                   ans= min(ans, currans);
               }
            }

        }
        
        if(src !=-1){
           return  dp2[mask][src]=ans;
        }else{
            return ans;
        }
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        
        
      int n=graph.size();
        
      int mask= 1<<n;
        
     mask--;
        
        cout<<mask<<endl;
        
        pairdistance(graph);
        
        memset(dp2, -1, sizeof(dp2));
        
        
//         for(int i=0; i<n;i++){
            
//             for(int j=0; j<n;j++){
                
//                 cout<<dp1[i][j]<<" ";
//             }
            
//             cout<<endl;
//         }
        
        return helper(mask, -1);
        
      
        
        
        
      
    }
};