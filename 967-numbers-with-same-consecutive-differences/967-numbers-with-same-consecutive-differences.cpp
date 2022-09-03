class Solution {
public:
    void helper(int index, int last, vector<int> & ans, int currpath, int n, int k){
        
        
        if(index==n+1){
            
           ans.push_back(currpath);
            return;
        }
        
        int val1= last+k;
        int val2= last-k;
        
        if(val1>=0 and val1<=9){
            helper(index+1, val1, ans, currpath*10+val1, n, k);
        }
        if(val2>=0 and val2<=9 and val1 !=val2){
            
            helper(index+1, val2, ans, currpath*10+val2, n, k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
      
        vector<int> ans;
       
        
        for(int i=1;i<=9;i++){
            
            helper(2, i, ans, i, n, k);
        }
        return ans;
    }
};