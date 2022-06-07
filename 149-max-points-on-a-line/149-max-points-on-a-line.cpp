class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      
       
        
        int n=points.size();
         int maxval=1;
        for(int i=0; i<n;i++){
             map<pair<int, int>, int > m;
            for(int j=i+1; j<n;j++){
                
                int val1= points[j][1]- points[i][1];
                int val2= points[j][0]-points[i][0];
                
                if(val2 ==0){
                    
                    m[{1,0}]++;
                }else{
                    
                    int val= __gcd(abs(val1), abs(val2));
                   if(val1>=0 and val2>0){
                       
                       val1/=val;
                       val2/=val;
                       m[{val1, val2}]++;
                       
                   }else if(val1<=0 and val2<0){
                       
                         val1/=val;
                       val2/=val;
                       m[{-1*val1, -1*val2}]++;
                       
                   }else{
                      val1=abs(val1);
                       val2= abs(val2);
                      val1/=val;
                       val2/=val;
                      m[{-1*val1, val2}]++;
                       
                   }
                }
            }
            
            for(auto  x: m){
            
            maxval= max(maxval, x.second+1);
            // // cout<<x.first<<" "<<x.second<<endl;
            }
            // cout<<maxval<<endl;
            
        }
        
       
        
      
        return maxval;
    }
};