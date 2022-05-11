int dp[301][5001];
class Solution {
public:
    int helper( int id, int amount, vector<int> & arr){
        
        if(amount==0){
            return 1;
        }
        if(id==arr.size()){
            return 0;
        }
         if(dp[id][amount] !=-1){
             return dp[id][amount];
         }
        int ans= helper(id+1, amount, arr );
        if((amount- arr[id])>=0){
            ans+= helper(id, amount-arr[id], arr);
        }
        
        return dp[id][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
         memset(dp, -1, sizeof(dp));
        return helper(0, amount, coins);
    }
};