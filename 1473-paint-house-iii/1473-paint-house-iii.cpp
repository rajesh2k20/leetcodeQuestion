class Solution {
public:
    int dp[101][31][101];
    int  helper(int index, int lastcolor, vector<int> & arr, vector<vector<int>> & cost, int m, int n, int target){
        
        
        if(index==arr.size()){
            
            if(target==0){
               return 0; 
            }else{
                return 1e9;
            }
        }
        if(target<0){
            return 1e9;
        }
        
        if(dp[index][lastcolor][target] !=-1){
            
            return dp[index][lastcolor][target];
        }
        
        int ans=1e9;
        
        if(arr[index] !=0){
            
            if(arr[index]==lastcolor){
                
               ans= helper(index+1, lastcolor, arr, cost, m, n, target); 
            }else{
                
             ans= helper(index+1, arr[index], arr, cost, m,n, target-1);
                
            }
            return dp[index][lastcolor][target]=ans;
        }else{
            
            for(int i=0; i<n;i++){
                
                int currans=0;
                
                if(lastcolor==(i+1)){
                    
                  currans= cost[index][i]+helper(index+1, i+1, arr, cost, m, n, target);
                    
                }else{
                  
                  currans=cost[index][i]+helper(index+1, i+1, arr, cost, m, n, target-1);
                }
                
                ans= min(ans, currans);
            }
            
            return dp[index][lastcolor][target]=ans;
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
       
        for(int i=0; i<=m;i++){
            
            for(int j=0;j<=n;j++){
                
                
                for(int k=0; k<=m;k++){
                    
                    dp[i][j][k]=-1;
                }
                
            }
        }
        
        int ans= helper(0,0,houses, cost, m,n, target);
        
        if(ans>=1e9){
            return -1;
        }else{
            return ans;
        }
    }
};