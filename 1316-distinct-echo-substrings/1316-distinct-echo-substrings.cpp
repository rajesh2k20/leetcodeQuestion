class Solution {
public:
    int distinctEchoSubstrings(string str) {
        
      set<int> s;
       int mod=1e9+7; 
      for(int len=0; len<str.size();len++){
          
          int j=len+1;
          int i=len;
          long long  p1=1;
          long long val1=0;
          long long val2=0;
          
          while(i>=0 and j<str.size()){
              
               int curr1= (str[i]-'a') +1;
               int curr2= (str[j]-'a') +1;
               val1+= (1LL*curr1* p1)%mod;
               val1%=mod;
               p1*=31;
               p1%=mod;
              
              val2= (1LL*val2*31)%mod+ curr2;
              val2%=mod;
              
              if(val1==val2){
                  // cout<<i<<" "<<j<<" "<<val1<<endl;
                  s.insert(val1);
              }
              i--;
              j++;
              
               
          }
      }
        
        return s.size();
        
    }
};