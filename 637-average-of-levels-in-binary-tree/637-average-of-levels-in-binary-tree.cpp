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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0){
            
            int size=q.size();
            double sum=0;
            
            for(int j=0; j<size;j++){
                
                TreeNode* curr= q.front();
                q.pop();
                
                sum+= curr->val;
                
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
            
            double ans1=  sum/size;
            
            ans.push_back(ans1);
        }
        
         return ans;
    }
    
   
};