class Solution {
public:
    void get(int index, int k, int n, vector<int> &path, vector<vector<int>> & ans){
        
        if(k==0 and n==0){
            ans.push_back(path);
            return ;
        }
        if(k<0){
            return ;
        }
        if(n<=0 and k>0){
            return ;
        }
        
        for(int i=index; i<=9;i++){
            
            if(n-i>=0){
                path.push_back(i);
                get(i+1, k-1, n-i, path, ans);
                path.pop_back();
                
            }else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
      
     vector<vector<int>> ans;
     vector<int> path;
     get(1, k, n, path, ans);
     return ans;
    }
};