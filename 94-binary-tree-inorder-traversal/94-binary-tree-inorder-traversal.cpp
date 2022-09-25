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
    vector<int> inorderTraversal(TreeNode* root) {
      
      if(root==NULL){
          
          return {};
      }
       stack<pair<TreeNode*, int>> s;
        
      s.push({root, 1});
        
        vector<int> ans;
        
      while(s.size()>0){
          
          
          pair<TreeNode*, int> curr= s.top();
          
          if(curr.second==1){
             s.pop();
              s.push({curr.first, 2});  
              if(curr.first->left != NULL){
                  s.push({curr.first->left, 1});
              }
          }else if(curr.second==2){
              ans.push_back(curr.first->val);
              s.pop();
              s.push({curr.first, 3});
               if(curr.first->right != NULL){
                  s.push({curr.first->right, 1});
              }
          }else{
              
              s.pop();
          }
          
         
              
         
          
          
          
      }
        
        return ans;
      
    }
};