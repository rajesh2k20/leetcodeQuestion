class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
      set<int> s1;
      set<int> s2;
        
      for(int i=0; i<matrix.size();i++){
          
          for(int j=0; j<matrix[0].size();j++){
              
              if(matrix[i][j]==0){
                  
                  s1.insert(i);
                  s2.insert(j);
              }
          }
      }
        
     for(auto  x: s1){
         
         int row=x;
         
         for(int i=0; i<matrix[0].size();i++){
             
             matrix[row][i]=0;
         }
     }
        
    for(auto  x: s2){
         
         int col=x;
         
         for(int i=0; i<matrix.size();i++){
             
             matrix[i][col]=0;
         }
     }
        
        
    
        
    }
};