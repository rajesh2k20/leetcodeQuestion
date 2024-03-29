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
    int ans=0;
    int count=0;
    bool get(TreeNode * root, int k){
        
        if(root==NULL){
            return false;
        }
        
       bool ans1= get(root->left, k);
        if(ans==true){
            return true;
        }
        count++;
        if(count==k){
            ans=root->val;
            return true ;
        }
      return   get(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
       ans=0;
      count=0;
      get(root, k);
        return ans;
    }
};