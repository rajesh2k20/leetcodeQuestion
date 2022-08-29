
class dsu{
    public:
     int *par;
     int *height;
     int size;
    dsu(int n){
        par=new int[n];
        height=new int[n];
        size=n;
        for(int i=0;i<n;i++){
            par[i]=i;
            height[i]=1;
        }
    }
    
    int root(int a){
        
        if(a==par[a]){
            return a;
        }
        return par[a]=root(par[a]);
    }
    
    bool find(int a,int b){
        int roota= root(a);
        int rootb=root(b);
        return roota==rootb;
    }
    
    bool un(int a,int b){
      int roota= root(a);
      int rootb=root(b);  
      if(roota==rootb){
          return  true;
      }else{
          size--;
          int ha=height[roota];
          int hb=height[rootb];
          if(ha>hb){
              par[rootb]=roota;
          }else if(ha<hb){
              par[roota]=rootb;
          }else{
              par[roota]=rootb;
              height[rootb]++;
              
          }
      }
        return false;
    }
    
    
};
class Solution {
public:
    int distance[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
       dsu d(grid.size()*grid[0].size()); 
      int count=0;
      
      for(int i=0;i<grid.size();i++){
          for(int j=0;j<grid[i].size();j++){
             if(grid[i][j]=='0'){
                 count++;
                 continue;
             }
             
            for(int k=0;k<4;k++){
                int r= i+distance[k][0];
                int c= j+distance[k][1];
                if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]=='1'){
                    int val1= i*grid[0].size()+j;
                    int val2= r*grid[0].size()+c;
                    d.un(val1,val2);
                }
            }
          }
      }
       // cout<<d.size;
       int n= grid.size();
        int m=grid[0].size();
        //cout<<count<<endl;
        return d.size-count;
    }
};