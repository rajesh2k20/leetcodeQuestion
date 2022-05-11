int dp[1001];
class Solution {
public:
    int helper(int id, vector<vector<int>> & books, int w){
        
        if(id==books.size()){
            return 0;
        }
        
        
        int sum=0;
        int maxval=-1e9;
        int ans=1e9;
        if(dp[id] !=-1){
            return dp[id];
        }
        for(int i=id; i<books.size();i++){
          
         sum+=books[i][0];
         maxval=max(maxval, books[i][1]);
         if(sum<=w){
          int curr= maxval+ helper(i+1, books, w);
           ans=min(ans, curr);
         }else{
             break;
         }
            
        }
        return dp[id]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
       
      memset(dp, -1, sizeof(dp));
      return helper(0, books, shelfWidth);
        
    }
};