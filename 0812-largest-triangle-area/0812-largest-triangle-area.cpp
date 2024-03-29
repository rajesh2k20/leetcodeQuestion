class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
     
      
      int n=points.size();
        
      double ans=0;
      for(int i=0; i<n;i++){
          
          for(int j=i+1; j<n;j++){
              
              for(int k=j+1; k<n;k++){
                  
                  int x1= points[i][0];
                  int y1= points[i][1];
                  int x2= points[j][0];
                  int y2= points[j][1];
                  int x3=points[k][0];
                  int y3= points[k][1];
                  
                  int val1= x1*(y2-y3);
                  int val2= x2*(y3-y1);
                  int val3= x3*(y1-y2);
                  
                  double val= abs(val1+val2+val3);
                  
                  val/=2.0;
                  
                  ans= max(ans, val);
                  
                  
              }
          }
      }
        
        return ans;
    }
};