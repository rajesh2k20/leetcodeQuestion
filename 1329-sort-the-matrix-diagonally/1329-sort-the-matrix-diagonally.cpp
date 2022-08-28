class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
    
      for(int l=1; l<mat.size();l++){
          
          
          int j=0;
          int i=l;
          int fre[101];
          memset(fre, 0, sizeof(fre));
         while(i<mat.size() and j<mat[0].size()){
             
            fre[mat[i][j]]++; 
             i++;
             j++;
         }
          
         j=0;
         i=l;
          
         int index=0;
          
         while(index<=100 and i<mat.size() and j<mat[0].size()){
             
             if(fre[index]==0){
                 index++;
                 continue;
             }
             mat[i][j]=index;
             i++;
             j++;
             fre[index]--;
         }
          
          
          
          
      }
        
        
    for(int l=0; l<mat[0].size();l++){
          
          
          int j=l;
          int i=0;
          int fre[101];
          memset(fre, 0, sizeof(fre));
         while(i<mat.size() and j<mat[0].size()){
             
            fre[mat[i][j]]++; 
             i++;
             j++;
         }
          
         j=l;
         i=0;
          
         int index=0;
          
         while(index<=100 and i<mat.size() and j<mat[0].size()){
             
             if(fre[index]==0){
                 index++;
                 continue;
             }
             mat[i][j]=index;
             i++;
             j++;
             fre[index]--;
         }
          
          
          
          
      }
    
        
        return  mat;
        
    }
};