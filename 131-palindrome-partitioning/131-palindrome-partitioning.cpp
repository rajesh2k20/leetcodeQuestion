class Solution {
public:
    
    bool  ispalid(string & str){
        
        
        int i=0;
        int j=str.size()-1;
        
        while(i<j){
            
            if(str[i] != str[j]){
                
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    bool isvalid(vector<string> & path){
        
        
        for(int i=0; i<path.size();i++){
            
            bool check=ispalid(path[i]);
            if(check==false){
                
                return false;
            }
        }
        
        return true;
    }
    void helper(int index, string & str, vector<vector<string>> & ans, vector<string> & path){
        
        
        // cout<<index<<" ";
        if(index==str.size()){
            
            bool check= isvalid(path);
            if(check==true){
                
                ans.push_back(path);
                
            }
            
            return;
        }
        
        if(index>str.size()){
            return ;
        }
        
        
        for(int i=index; i<str.size();i++){
            
            path.push_back(str.substr(index, i-index+1));
            
            helper(i+1, str, ans, path );
            
            path.pop_back();
        }
        
        
    }
    vector<vector<string>> partition(string s) {
        
        
        vector<vector<string>> ans;
        vector<string> path;
        helper(0,s,ans, path);
        return ans;
        
    }
};