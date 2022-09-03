class dsu{
  public:
    int *par;
    int * height;
    int size;
    int comp;
    
    dsu(int n){
        
      comp=n;
      par= new int[n];
      height=new int[n];
        
      for(int i=0; i<n;i++){
          par[i]=i;
          height[i]=1;
      }
        
     
     
    }
    
    
    int root(int node){
        
        if(par[node]==node){
            return node;
        }
        
        return par[node]=root(par[node]);
    }
    
    
    void un(int node1, int node2){
        
        int root1= root(node1);
        int root2= root(node2);
        
        if(root1==root2){
            return ;
        }else{
            comp--;
            if(height[root1]>height[root2]){
                
                par[root2]=root1;
                
                
            }else if(height[root1]<height[root2]){
                par[root1]=root2;
            }else{
                
                par[root2]=root1;
                
                height[root1]++;
                
            }
        }
    }
    
    bool find(int node1, int node2){
        
        return root(node1)==root(node2);
        
    }
    
    
    
    
    
};

class Solution {
public:
    bool check(string & str1, string & str2 ){
        
        
        int diff=0;
        
        for(int i=0; i<str1.size();i++){
            
            if(str1[i] !=str2[i]){
                diff++;
            }
        }
        
        if(diff==0  || diff==2){
            return true;
        }else{
            return false;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        
      int n=strs.size();
        
      dsu d(n);
        
      for(int i=0; i<n;i++){
          
          for(int j=i+1; j<n;j++){
              
              if(check(strs[i], strs[j])==true){
                  
                  d.un(i,j);
              }
          }
      }
        
    return d.comp;
    }
};