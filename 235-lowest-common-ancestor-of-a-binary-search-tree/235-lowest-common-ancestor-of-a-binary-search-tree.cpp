/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode*  helper(TreeNode* root, int p1, int p2){
        
        
        if(root==NULL){
            return NULL;
        }
        
        if(root->val>=p1 and root->val<=p2){
            return root;
        }else if(root->val<p1){
            return helper(root->right, p1, p2);
        }else{
             return helper(root->left, p1, p2);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int p1= p->val;
        int p2= q->val;
        if(p1>p2){
            swap(p1,p2);
        }
        
        return helper(root, p1, p2);
        
        
    }
};