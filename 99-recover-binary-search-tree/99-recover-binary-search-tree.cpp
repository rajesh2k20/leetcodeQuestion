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
    int val=-1e9;
    TreeNode * p1=NULL;
    TreeNode * p2=NULL;
    TreeNode * pre=NULL;
    void get(TreeNode * root){
        
        if(root==NULL){
            return;
        }
        
        get(root->left);
        if(root->val<val){
            
            if(p1==NULL){
                p1=pre;  
            }
            p2=root;
        }else{
            val=root->val;
            
        }
        // cout<<val<<endl;
        pre=root;
        get(root->right);
    }
    void recoverTree(TreeNode* root) {
        
         p1=NULL;
         p2=NULL;
         pre=NULL; 
        val=-1e9;
        get(root);
        // cout<<val<<endl;
        if(p1==NULL){
            cout<<"TRUE";
        }
        if(p2==NULL){
            cout<<"TRE";
        }
       swap(p1->val, p2->val);
        

    }
};