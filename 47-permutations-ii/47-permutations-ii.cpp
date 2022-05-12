class Solution {
public:
    void helper( vector<int> & visited, vector<int> & nums, vector<int> & path, vector<vector<int>> & ans){
        
        
        if(path.size()==nums.size()){
            
            ans.push_back(path);
            return ;
        }
        
        
        set<int> s;
        
        for(int i=0; i<nums.size();i++){
            
            if(visited[i]==0 and s.count(nums[i])==0){
                
                visited[i]=1;
                s.insert(nums[i]);
                path.push_back(nums[i]);
                helper(visited, nums, path, ans);
                path.pop_back();
                visited[i]=0;
            }
        }
        
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        vector<int> visited(n,0);
         helper(visited, nums, path, ans);
        return ans;
        
    }
};