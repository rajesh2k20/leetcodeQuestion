class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
       
    vector<vector<int>> arr;
     arr.push_back({0, startFuel});
     for(int i=0; i<stations.size();i++){
         arr.push_back(stations[i]);
     }
     arr.push_back({target,0});   
     
     int n= arr.size();
     long long dp[n][n];
     memset(dp, -1e9, sizeof(dp));
     for(int i=0; i<n;i++){
         
         for(int j=0; j<n;j++){
             
             if(i==0){
                 dp[i][j]= arr[i][1];
                 continue;
             }
             
             if(j==0){
                 
                 if(dp[i-1][j]-(arr[i][0]-arr[i-1][0])>=0){
                     
                     dp[i][j]= dp[i-1][j]-(arr[i][0]-arr[i-1][0]);
                 }else{
                     dp[i][j]=-1e9;
                 }
             }else{
                 dp[i][j]=-1e9;
                 if(dp[i-1][j]-(arr[i][0]-arr[i-1][0])>=0){
                     
                     dp[i][j]= dp[i-1][j]-1LL*(arr[i][0]-arr[i-1][0]);
                 }
                 if(dp[i-1][j-1]-(arr[i][0]-arr[i-1][0])>=0){
                     
                    dp[i][j]= max(dp[i][j], 1LL*(dp[i-1][j-1]-(arr[i][0]-arr[i-1][0])+ arr[i][1]));
                 }
                 
             }
         }
     }
        
//      for(int i=0; i<n;i++){
         
//         for(int j=0; j<n;j++){
            
//             cout<<dp[i][j]<<" ";
//         }
//          cout<<endl;
//      }
        
        for(int i=0; i<n;i++){
            
            if(dp[n-1][i]>=0){
                return i;
            }
        }
        return -1;
    }
};