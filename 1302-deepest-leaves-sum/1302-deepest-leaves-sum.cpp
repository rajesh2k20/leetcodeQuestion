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
    void dfs(TreeNode * root, int curr, int level, int & ans){
        
        if(root == NULL){
            return ;
        }
        
        if(curr==level){
            ans+= root->val;
        }
        
        dfs(root->left, curr+1, level, ans);
        dfs(root->right, curr+1, level, ans);
    }
    int dfs(TreeNode * root){
        
        if(root==NULL){
            return -1;
        }
        
      int level1= dfs(root->left);
      int level2= dfs(root->right);
      return max(level1, level2)+1;
        
    }
    int deepestLeavesSum(TreeNode* root) {
        
      int level= dfs(root);
       int ans=0;
        dfs(root, 0, level, ans);
        return ans;
      
        
    }
};