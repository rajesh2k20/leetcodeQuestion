class Solution {
public:
    int dp[10300][31];
    int mod=1e9+7;
    int limit=10300;
    long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
    void helper(){
        
        dp[0][0]=1;
        
        
        for(int i=1; i<limit;i++){
            
            for(int j=0; j<=min(30,i);j++){
              
                
                if(j==0){
                    dp[i][j]=1;
                    continue;
                }
                if(i==j){
                    
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]= 1LL*(1LL*dp[i-1][j]+1LL*dp[i-1][j-1])%mod;
                
            }
        }
        
        
    }
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
      
        memset(dp, 0, sizeof(dp));
        
        helper();
      
      vector<int> ans;
        
      for(int i=0; i<queries.size();i++){
          
          int n=queries[i][0];
          int val= queries[i][1];
          
          if(val==1){
            ans.push_back(1);
              continue;
         }
          
        
          long long  currans=1;
         for(int i=2;i*i<=val;i++){
             
             if(val%i==0){
                 
                 int  count=0;
                 
                 while(val%i==0){
                     count++;
                     val=val/i;
                 }
                 
                 currans= 1LL*currans*dp[n-1+count][count];
                 currans%=mod;
             }
         }
          
         if(val !=1){
             
            currans=1LL*currans*dp[n][1];
            currans%=mod;
             
         }
          ans.push_back(currans);
          
           
        
      }
        
        return ans;
        
        
      
    }
};