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
    void helper(TreeNode * root, int & ans, int val){
        
        if(root==NULL){
            return ;
        }
        
        if(root->val>=val){
            ans++;
        }
        helper(root->left, ans, max(val, root->val));
        helper(root->right, ans, max(val, root->val));
        
    }
    int goodNodes(TreeNode* root) {
       
        int ans=0;
        
        
        helper(root, ans, -1e9);
        return ans;
        
    }
};