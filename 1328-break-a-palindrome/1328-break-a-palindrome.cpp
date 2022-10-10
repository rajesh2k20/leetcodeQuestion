class Solution {
public:
    string breakPalindrome(string str) {
        
        
      int size= str.size();
      
      for(int i=0; i<size/2;i++){
          
          if(str[i] !='a'){
              str[i]='a';
              return str;
          }
      }
        
        if(str.size()==1){
            return "";
        }else{
            str[size-1]='b';
            return str;
        }
    }
};