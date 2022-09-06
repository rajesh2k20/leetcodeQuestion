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
    int get(TreeNode*  root, int level){
        
        if(root==NULL){
            return 0;
        }
        
        int lefth= get(root->left, level+1);
        int righth= get(root->right, level+1);
        
        return max(lefth, righth)+1;
    }
    bool isCompleteTree(TreeNode* root) {
        
        
        if(root==NULL){
            return true;
        }
        
        
        
        
     int depth= get(root, 0);
        
        if(depth==1){
            return true;
        }
       cout<<depth<<endl; 
    queue<TreeNode*> q;
       int level=1; 
        q.push(root);
        
        while(q.size()>0){
            
            int size= q.size();
            
            if(level !=depth-1){
                
                
                while(size--){
                    
                    TreeNode* curr= q.front();
                    q.pop();
                    
                    if(curr->left == NULL || curr->right==NULL){
                        cout<<"L1"<<endl;
                        return false;
                    }else{
                        
                        q.push(curr->left);
                        q.push(curr->right);
                    }
                }
                
            }else{
                
               // bool check=true;
                cout<<level<<endl;
               while(size>0){
                   
                    TreeNode* curr= q.front();
                    q.pop();
                   cout<<curr->val<<endl;
                   if(curr !=NULL and curr->left !=NULL and curr->right !=NULL){
                       size--;
                       continue;
                   }
                   else if(curr !=NULL and curr->left==NULL and curr->right !=NULL){
                       // cout<<"R"<<endl;
                       return false;
                   }else{
                       size--;
                       while(size>0){
                           
                           curr=q.front();
                           q.pop();
                           size--;
                           if(curr->left != NULL || curr->right !=NULL){
                               // cout<<"L"<<endl;
                               return false;
                           }
                       }
                   }
               }
                
                
                
            }
            
            level++;
        }
        
        return true;
        
    }
};