class Solution {
public:
    int dp[10][1<<10][2][2][2];
    int helper(string & str, int index, int mask, int toggle, int check, int check2){
    
        
    if(index==str.size()){
        
        if(check==1){
            return 1;
        }else{
            return 0;
        }
    }
        
    if(dp[index][mask][toggle][check][check2] !=-1){
        
        return dp[index][mask][toggle][check][check2];
    }
        
        
    int up=9;
     if(toggle==1){
         
         up=str[index]-'0';
         
     }
    
        int ansCount=0;
        
     for(int i=0; i<=up;i++){
         
         int new_toggle= 0;
         if(toggle==1){
           
             if(i== (str[index]-'0')){
                 new_toggle=1;
             }
         }
         
         if(check2==1){
             int bit=  ((mask>>i) & 1);
         
         if(bit==1){
             
            ansCount+= helper(str, index+1, mask | (1<<i), new_toggle, 1,1); 
         }else{
             
             ansCount+= helper(str, index+1, mask|(1<<i), new_toggle, check,1);
         }
         }else{
             
             if(i==0){
               ansCount+=helper(str, index+1, mask, new_toggle, check, check2);  
             }else{
                ansCount+= helper(str, index+1, mask|(1<<i), new_toggle, check,1); 
             }
         }
         
     }
        
     return dp[index][mask][toggle][check][check2]=ansCount;
        
    
        
        
        
        
    }
    int numDupDigitsAtMostN(int n) {
        
       string str= to_string(n);
        
        memset(dp, -1, sizeof(dp));
        
        int ans= helper(str, 0,0,1,0,0);
        
        return ans;
    }
};