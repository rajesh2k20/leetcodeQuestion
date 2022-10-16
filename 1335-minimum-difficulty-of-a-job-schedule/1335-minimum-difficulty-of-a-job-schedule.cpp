int dp[301][20];
class Solution {
public:
    
    int helper(int index, int d, vector<int> & arr){
        
        if(d==0){
            
            
            if(index==arr.size()){
                return 0;
            }else{
                return 1e9;
            }
        }
        
        if(index==arr.size()){
            
            if(d==0){
                return 0;
            }else{
                return 1e9;
            }
        }
        
        if(dp[index][d] !=-1){
            
            return dp[index][d];
        }
        int maxval=0;
        int ans=1e9;
        for(int i=index; i<arr.size();i++){
            
           maxval= max(maxval, arr[i]);
           int currans= maxval+ helper(i+1, d-1, arr);
            ans=min(ans, currans);
           
        }
        
        return dp[index][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        
        
     for(int i=0; i<jobDifficulty.size();i++){
         
           for(int j=0; j<=d;j++){
               
               dp[i][j]=-1;
           }
     }
       
        
      int ans=helper(0, d, jobDifficulty);
    
        if(ans>=1e9){
            return -1;
        }else{
            return ans;
        }
    }
};