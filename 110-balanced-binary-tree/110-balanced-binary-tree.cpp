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
    pair<bool, int> helper(TreeNode* root){
        
        
        if(root==NULL){
            
            return {true, 0};
        }
        
        pair<bool, int> leftans= helper(root->left);
        if(leftans.first==false){
            return {false, 1};
        }
        pair<bool, int> rightans=helper(root->right);
        
        if(rightans.first==false){
            return {false, 1};
        }
        
        int diff= abs(leftans.second- rightans.second);
        
        if(diff>1){
            return {false, 1};
        }else{
            
            return {true, max(leftans.second, rightans.second)+1};
        }
        
        
    }
    bool isBalanced(TreeNode* root) {
        
      
    return helper(root).first;
    }
};