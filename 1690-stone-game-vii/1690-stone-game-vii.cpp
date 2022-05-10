int dp[1001][1001][3];
class Solution {
public:
    int helper(int i, int j, int pos, vector<int> & arr){
        
         if(i>=j){
             return 0;
         }
         
        if(dp[i][j][pos] !=-1 ){
            
            return  dp[i][j][pos];
        }
        
        
        int ans1=0;
        int ans2=0;
        if(i==0){
         
        if(pos==1){
            
            ans1= arr[j]-arr[i]+ helper(i+1, j, 2,arr);
            ans2= arr[j-1]+ helper(i, j-1, 2, arr);
             return dp[i][j][pos]=max(ans1, ans2);
        }else{
            
            ans1= -1*(arr[j]-arr[i]) + helper(i+1, j, 1,arr);
            ans2=  -1*(arr[j-1])+ helper(i, j-1,1, arr);
            return dp[i][j][pos]=min(ans1, ans2);
        }
            
        }else{
            
         if(pos==1){
            
            ans1= arr[j]-arr[i]+ helper(i+1, j, 2,arr);
            ans2= (arr[j-1]-arr[i-1])+ helper(i, j-1, 2, arr);
             return dp[i][j][pos]=max(ans1, ans2);
        }else{
            
            ans1= -1*(arr[j]-arr[i]) + helper(i+1, j, 1,arr);
            ans2=  -1*(arr[j-1]-arr[i-1])+ helper(i, j-1,1, arr);
             return dp[i][j][pos]=min( ans1, ans2);
        }   
            
        }
        
        
    }
    int stoneGameVII(vector<int>& stones) {
        
        int n= stones.size();
        vector<int> arr(n, 0);
        memset(dp, -1, sizeof(dp));
        arr[0]=stones[0];
        for(int i=1; i<n;i++){
            arr[i]=arr[i-1]+stones[i];
        }
        
        return helper(0,n-1, 1, arr);
        
        
        
    }
};