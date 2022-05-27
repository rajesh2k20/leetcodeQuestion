class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int ans=0;
        if(n<0){
            
          int val= 1<<31;
          n=n^val;
          ans++;
        }
        
        
        
        while(n>0){
            
            
            if( (n&1)==1){
                ans++;
            }
            
            n=n/2;
        }
        
        return ans;
        
        
    }
};