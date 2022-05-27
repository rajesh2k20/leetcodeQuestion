int dp[33][2][2];
class Solution {
public:
    int helper(int index, string & str, int  last, int toggle){
        
        if(index==str.size()){
            return 1;
        }
        
        if(dp[index][last][toggle] !=-1){
            return  dp[index][last][toggle];
        }
        
        int up= 1;
        if(toggle==1){
            
            up=str[index]-'0';
        }
        int ans=0;
       for(int i=0; i<=up;i++){
           
           if(last==1 and i==1){
               continue;
           }
           
           ans+= helper(index+1, str, i, toggle &(i==up));
       }
      return dp[index][last][toggle]=ans;
    }
    string get(int n){
        
        
        string ans;
        while(n>0){
            
            if(( n& 1)==1){
                ans+='1';
            }else{
                ans+='0';
            }
            
            n=n/2;
            
        }
        
        return ans;
    }
    int findIntegers(int n) {
        
        
        string str= get(n);
        reverse(str.begin(), str.end());
        memset(dp, -1, sizeof(dp));
        return helper(0, str, 0,1);
        
        
        
    }
};