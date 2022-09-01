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
    vector<int> helper(TreeNode*  root, int & ans){
        
        
        if(root==NULL){
            return {true,0,0,0};
        }
        
        if(root->left != NULL and root->right != NULL){
           vector<int> p1= helper(root->left, ans);
       vector<int > p2= helper(root->right, ans);
            
            if(p1[0]==true and p2[0]==true and root->val> p1[2] and root->val<p2[3] ){
                
                int mysum=p1[1]+p2[1]+root->val;
                 ans= max(ans, mysum);
                return {true, mysum, p2[2], p1[3]};
            }else{
                
               int mysum=p1[1]+p2[1]+root->val;
                return {false, mysum, p2[2],p1[3]};
            }
            
        }else if(root->left != NULL and root->right == NULL){
            
            vector<int> p1= helper(root->left, ans);
            
            if(p1[0]==true  and root->val> p1[2]  ){
                
                int mysum=p1[1]+root->val;
                 ans= max(ans, mysum);
                return {true, mysum, root->val, p1[3]};
            }else{
                
               int mysum=p1[1]+root->val;
                return {false, mysum, root->val, p1[3]};
            }
            
            
        }else if(root->left == NULL and root->right != NULL){
            
           vector<int> p2= helper(root->right, ans);
            
            if(p2[0]==true  and root->val < p2[3]  ){
                
                int mysum=p2[1]+root->val;
                 ans= max(ans, mysum);
                return {true, mysum, p2[2] ,root->val};
            }else{
                
               int mysum= p2[1]+root->val;
                return {false, mysum, p2[2] ,root->val};
            } 
            
            
        }else{
            ans= max(ans, root->val);
            return {true, root->val, root->val, root->val};
        }
        
        
    }
    int maxSumBST(TreeNode* root) {
        
        int ans=0;
        
        helper(root, ans);
        return ans;
        
    }
};