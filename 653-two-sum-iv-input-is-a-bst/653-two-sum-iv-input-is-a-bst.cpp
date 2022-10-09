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
    bool ispresent(TreeNode* root,  int val ){
        
        if(root==NULL){
            return false;
        }
        
        if(root->val==val){
            return true;
        }
        if(root->val>val){
            
         return   ispresent(root->left,val );
        }else{
            
             return   ispresent(root->right,val );
            
        }
    }
    bool helper(TreeNode* root, int k, TreeNode* realroot){
        
      if(root==NULL){
            return false;
        }
        
        int val= k-root->val;
        
        if(val != root->val){
            
            bool currans= ispresent(realroot, val);
            if(currans==true){
                return true;
            }
        }  
        
        return helper(root->left, k, realroot) || helper(root->right, k, realroot);
    }
    bool findTarget(TreeNode* root, int k) {
        
        
        return helper(root, k, root);
    }
};