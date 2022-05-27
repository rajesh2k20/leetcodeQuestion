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
    void helper(TreeNode * root, map<TreeNode*, pair<int, int>>&  m){
        
        if(root==NULL){
            m[root]={-1e9,0};
            return ;
        }
        
        helper(root->left, m);
        helper(root->right, m);
        int val1= root->val+ m[root->left].second +m[root->right].second;
        int val2= root->val+ max(m[root->left].second, m[root->right].second);
        m[root]={max({val1, val2, root->val}), max(val2, root->val)};
        
        
    }
    int maxPathSum(TreeNode* root) {
        
        
        map<TreeNode*, pair<int, int>> m;
        helper(root, m);
        int ans=-1e9;
        cout<<m.size()<<endl;
        for(auto  x: m){
             // cout<<x.second.first<<endl;
            // if(x.first==NULL){
            //     continue;
            // }
            ans= max(ans, x.second.first);
        }
        return ans;
        
    }
};