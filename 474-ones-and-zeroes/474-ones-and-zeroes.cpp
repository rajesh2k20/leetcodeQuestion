int dp[601][101][101];
class Solution {
public:
    
    int  helper(int index, int n, int m, vector<pair<int, int>> & arr){
        
      if(index==arr.size()){
          return 0;
      }  
      int ans=0;  
    if(dp[index][n][m] != -1){
        return dp[index][n][m];
    }
      if(n>= arr[index].second and m>=arr[index].first){
          
        ans= max(ans, 1+helper(index+1, n-arr[index].second, m-arr[index].first, arr));  
      }
        ans= max(ans, helper(index+1,n, m, arr ));
        return dp[index][n][m]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
      
      vector<pair<int, int>> arr;
        
      for(int i=0; i<strs.size();i++){
          
          int count0=0;
          int count1=0;
          for(int j=0; j<strs[i].size();j++){
              
              if(strs[i][j]=='1'){
                  count1++;
              }else{
                  count0++;
              }
          }
          
          arr.push_back({count0, count1});
      }
        
       memset(dp, -1, sizeof(dp)); 
      return helper(0, n, m, arr);
        
       
    }
};