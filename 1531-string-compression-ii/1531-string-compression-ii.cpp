int dp[110][111][30][111];
class Solution {
public:
    int helper(int index, int count, char ch, int k, string & str){
        
        
        if(str.size()==index){
          
           if(count==0 ||count==1){
               return count;
           }else{
               
               return to_string(count).size()+1;
           }
            
        }
        
        if(ch=='$'){
            
            
            
            if(dp[index][count][0][k] !=-1){
                
                cout<<"2"<<endl;
                
                return dp[index][count][0][k];
            }
        }else{
            
           if(dp[index][count][(ch-'a')+1][k] !=-1){
                
                return dp[index][count][(ch-'a')+1][k];
            } 
        }
        
        
        if(ch=='$'){
            
            if(k>0){
                
                int ans1= helper(index+1, 1, str[index], k, str);
                int ans2= helper(index+1, count, ch, k-1, str );
                
                return dp[index][count][0][k]=min(ans1, ans2);
                
                
                
            }else{
                
                return dp[index][count][0][k]=helper(index+1, count+1, str[index], k, str);
            }
            
            
        }
        
        if(k>0){
            
            int ans1= helper(index+1, count, ch, k-1, str);
            
            int ans2= 0;
            
            
            if(str[index]==ch){
               ans2+= helper(index+1, count+1, ch, k, str);
            }else{
                
              if( count==1){
                  
              ans2+=count+ helper(index+1, 1, str[index], k, str);
              
           }else{
               
               ans2+= to_string(count).size()+1+helper(index+1, 1,                                  str[index], k, str);;
           }
                
            }
                
            return dp[index][count][(ch-'a')+1][k]=min(ans1, ans2);
            
            
            
            
            
        }else{
            
            if(str[index]==ch){
              return dp[index][count][(ch-'a')+1][k]= helper(index+1, count+1, ch, k, str);
            }else{
                
              if( count==1|| count==0){
               return dp[index][count][(ch-'a')+1][k]=count+helper(index+1, 1, str[index], k, str);
           }else{
               
               return dp[index][count][(ch-'a')+1][k]=to_string(count).size()+1+helper(index+1, 1,                                  str[index], k, str);
           }
              // return helper(index+1, 1, str[index], k, str);  
            }
        }
        
        
    }
    int getLengthOfOptimalCompression(string s, int k) {
      
        int n=s.size();
        
        for(int i=0; i<=n;i++){
            
            for(int j=0; j<=100;j++ ){
                
                for(int q=0; q<=26;q++){
                    
                    for(int p=0; p<=k;p++){
                        
                        dp[i][j][q][p]=-1;
                    }
                }
            }
        }
         return helper(0, 0, '$', k, s);
    
    }
};