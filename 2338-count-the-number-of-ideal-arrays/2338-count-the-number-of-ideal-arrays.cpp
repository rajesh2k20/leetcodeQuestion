class Solution {
public:
     int dp[30];
    int mod=1e9+7;
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
    int helper(int val,int count, int maxval, int n){
        
        
         if(count>n){
             return 0;
         }
        
        
        int ans=dp[count-1];
        // cout<<val<<" "<<count<<endl;
        for(int i=val*2;i<=maxval;i+=val){
            
          ans+= helper(i, count+1, maxval,n);  
            ans%=mod;
        }
        
        return ans;
    }
    int idealArrays(int n, int maxval) {
        
     
        
      memset(dp, 0, sizeof(dp));
      dp[0]=1;
    
      for(int i=1; i<=min(29, n);i++){
          
          long long val1=1LL*dp[i-1]*(n-i);
          val1%=mod;
          val1= 1LL*val1*binpow(i, mod-2, mod);
          dp[i]= val1%mod;
          
      }
        
//      for(int i=0;i<30;i++){
         
//          cout<<dp[i]<<" ";
//      }
        
        // cout<<endl;
    
        int ans=0;
    
     for(int i=1; i<=maxval;i++){
         
         ans+= helper(i,1,maxval,n);
        ans%=mod;
        
     }
    
     
    
      
    
      return ans;
    }
};