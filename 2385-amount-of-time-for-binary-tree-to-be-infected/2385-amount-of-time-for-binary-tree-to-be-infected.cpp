/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode*  root, map<int, vector<int>> & m, int parent){
       
        if(root==NULL){
            return;
        }
        
        if(parent !=-1){
            m[root->val].push_back(parent);
            m[parent].push_back(root->val);
        }
        
        dfs(root->left, m, root->val);
        dfs(root->right, m, root->val);
        
    }
   void dfs(int src, int parent, int & ans, map<int, vector<int>> & m, int level){
      
       
       ans= max(ans, level);
       
      
       for(auto  x : m[src]){
           
           if(x !=parent){
               dfs(x, src, ans, m, level+1);
           }
       }
       

   }
    int amountOfTime(TreeNode* root, int start) {
      
        map<int, vector<int>> m;
        int ans=0;
        
        dfs(root, m, -1);
        
//         for(auto  x: m){
            
//             cout<<x.first<<" ";
//             for(auto  y: x.second){
//                 cout<<y<<" ";
//             }
//             cout<<endl;
//         }
        dfs(start, -1, ans, m, 0);
        
        return ans;
    }
};