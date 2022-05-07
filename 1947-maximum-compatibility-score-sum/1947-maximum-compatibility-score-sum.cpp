int dp[ (1<<(9))][10];
class Solution {
public:
    int get(vector<int> & arr1, vector<int> & arr2){
        
        int count=0;
      
        for(int i=0; i<arr1.size();i++){
            
            if(arr1[i]==arr2[i]){
                count++;
            }
        }
        
        return count;
    }
    int helper(int mask, int id, vector<vector<int>> & arr1, vector<vector<int>> & arr2){
        
         if(id== arr1.size()){
             return 0;
         }
         if( dp[mask][id] !=-1){
             
             return dp[mask][id];
         }
        int ans=0;
        for(int i=0; i<arr1.size();i++){
            
            if( ((mask >>i) & 1 ) ==0){
             int val= get(arr1[id], arr2[i]);   
             ans= max(ans, val+helper(mask |(1<<i), id+1, arr1, arr2) );    
            }
        }
        return dp[mask][id]=ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& arr1, vector<vector<int>>& arr2) {
        
     memset(dp, -1, sizeof(dp));    
    int ans=   helper(0, 0, arr1, arr2);
        return ans;
     
        
    }
};