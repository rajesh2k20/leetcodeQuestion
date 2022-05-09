class Solution {
public:
    void get( string & str, int index, vector<string> & ans, string  path,
             map<int, vector<char>> & m){
        
     if(index==str.size()){
         
         ans.push_back(path);
         return ;
     }   
      
     vector<char> arr= m[ str[index]-'0'];
     for(int i=0; i<arr.size();i++){
          get(str, index+1, ans, path+ arr[i], m);
     }
    }
    vector<string> letterCombinations(string digits) {
       if(digits.size()==0){
           return {};
       }
     map<int, vector<char>> m;
      m[2]={'a','b','c'};
      m[3]={'d','e','f'};
       m[4]={'g','h','i'};
         m[5]={'j','k','l'};
         m[6]={'m','n','o'};
         m[7]={'p','q','r','s'};
         m[8]={'t','u','v'};
         m[9]={'w','x','y','z'};
        string path;
        vector<string> ans;
     get(digits,0, ans,path ,m);
        return ans;
        
    
    }
};