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
    void helper(TreeNode* root, map<int, multiset<pair<int, int>>> & m, int r, int c  ){
        
        if(root==NULL){
            return ;
        }
        
        m[c].insert({r, root->val});
        
        helper(root->left, m, r+1, c-1);
        helper(root->right, m, r+1,c+1);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       
        map<int, multiset<pair<int, int>>> m;
        
        helper(root, m, 0,0);
        
        vector<vector<int>> arr;
        
        for(auto  x: m){
            
            vector<int> d;
            
            for(auto  y : x.second){
                
                d.push_back(y.second);
            }
            arr.push_back(d);
        }
        
        return arr;
    }
};