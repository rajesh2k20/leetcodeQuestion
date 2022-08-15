class Solution {
public:
    int romanToInt(string s) {
      map<string, int> m;
        
        m["I"]=1;
        m["V"]=5;
        m["X"]=10;
        m["L"]=50;
        m["C"]=100;
        m["D"]=500;
        m["M"]=1000;
        m["IV"]=4;
        m["IX"]=9;
        m["XL"]=40;
        m["XC"]=90;
        m["CD"]=400;
        m["CM"]=900;
        
      int ans=0;
        
     for(int i=0; i<s.size();i++){
         
         string str;
             str+=s[i];
         ans+=m[str];
     }
     
     for(int i=1; i<s.size();i++){
         
         string str;
         str+=s[i-1];
             str+=s[i];
         if(m.count(str)==1){
             string str1;
                 str1+=s[i];
             string str2;
             str2+=s[i-1];
             ans-=m[str1];
             ans-=m[str2];
             ans+=m[str];
         }
         
         
     }
        
        return ans;
    }
    
};