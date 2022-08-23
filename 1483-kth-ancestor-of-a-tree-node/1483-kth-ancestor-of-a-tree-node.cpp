vector<vector<int>> lca(100010, vector<int>(30,-1));
    
    
    
    int root;
class TreeAncestor {
public:
    
    TreeAncestor(int n, vector<int>& parent) {
      
       
        
       for(int j=0; j<=30;j++){
           
           for(int i=0; i<n;i++){
               
               if(j==0){
                   lca[i][j]= parent[i];
                   continue;
               }
               
               int par=lca[i][j-1];
              if(par !=-1){
                   lca[i][j]=lca[par][j-1];
              }
           }
       }
        
        
    }
    
    int getKthAncestor(int node, int k) {
        
        
       while(k>0 and node !=-1){
           
           int pos= log2(k);
           node=lca[node][pos];
           k-= (1<<pos);
       }
     return node;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */