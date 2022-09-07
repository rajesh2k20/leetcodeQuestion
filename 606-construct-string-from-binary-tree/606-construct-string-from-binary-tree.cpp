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
    string tree2str(TreeNode* root) {
        
        
        if(root==NULL){
            return "";
        }
        
        if(root->left==NULL and root->right ==NULL){
            
            return to_string(root->val);
        }
        else if(root->left !=NULL and root->right==NULL){
            
            string str1= tree2str(root->left);
            
            return to_string(root->val)+"("+str1+")";
            
        }else{
            
            string str1= tree2str(root->left);
            string str2= tree2str(root->right);
            
            return to_string(root->val)+"("+str1+")"+"("+str2+")";
            
        }
        
    }
};