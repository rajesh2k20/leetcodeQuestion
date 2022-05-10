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
    pair<int, int> helper( TreeNode * root, int & ans){
        
        if(root==NULL){
            return {0,0};
        }
        
        pair<int, int> p1= helper(root->left, ans);
        pair<int, int> p2= helper(root->right, ans);
        
        if(root->left != NULL and root->right != NULL){
            ans= max({1+p1.second, 1+p2.first, ans});
           
            return {1+ p1.second, 1+ p2.first};
        }else if(root->left !=NULL and root->right ==NULL){
            
            ans= max(ans, 1+p1.second);
            
            return {1+p1.second, 0};
        }else if(root->left == NULL and root-> right != NULL){
            
            ans= max(ans, 1+p2.first);
            
            return {0, 1+ p2.first};
        }else{
             return {0,0};
        }
        
    }
    int longestZigZag(TreeNode* root) {
     
      int ans=0; 
     helper(root, ans);
    
        return ans;
    }
};