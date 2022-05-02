class Solution {
public:
    int dp1[200][200];
     int dp2[200][200];
    int helper( int i, int k, int n){
        
        if(k !=0){
            
           if( i==n){
               return 1e9;
           }
        }
        if(k==0 and i==n){
            return 0;
        }
        if(k<0){
            return 1e9;
        }
        if(dp2[i][k] !=-1){
            return dp2[i][k];
        }
         int ans=1e9;
        for(int j=i;j<n;j++){
            
         ans= min(ans,dp1[i][j]+ helper(j+1, k-1, n));
         
        }
        return dp2[i][k]=ans;
    }
    int palindromePartition(string s, int k) {
     
       memset(dp1, 0, sizeof(dp1));
        int n=s.size();
        for(int gap=0; gap<=n;gap++){
            
            for(int i=0; i<n;i++){
                
                int j=i+gap;
                if(j>=n){
                    continue;
                }
                
                if(gap==0){
                    
                continue;
                }
                if(gap==1){
                    if(s[i]!=s[j]){
                        dp1[i][j]=1;
                    }
                    continue;
                }
                
               if(s[i]==s[j]){
                   dp1[i][j]= dp1[i+1][j-1];
               }else{
                  dp1[i][j]= dp1[i+1][j-1]+1; 
               }
                
                
                
                
            }
               
         }
        
        memset(dp2, -1, sizeof(dp2));
        
        return helper(0,k,n);
    }
};