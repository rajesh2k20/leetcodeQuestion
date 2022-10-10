class Solution {
public:
    string breakPalindrome(string str) {
        
        
      int size= str.size();
      
     string ans;
      for(int i=0; i<size;i++ ){
          
          
          if(size%2==1){
              
              if(i==size/2){
                  continue;
              }
          }
          
          for(int j=0; j<26;j++){
              
              char ch=j+'a';
              
              if(str[i]==ch){
                  
                  continue;
              }
              
              char temp= str[i];
              
              str[i]=ch;
              
             if(ans.size()==0){
                 ans=str;
             }else{
                 ans= min(ans, str);
             }
              
              str[i]=temp;
          }
      }
        
        return ans;
    }
};