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
    int index=0;
    TreeNode* helper( vector<pair<int, int>> & arr, int level){
        
        if(index==arr.size()){
            return NULL;
        }
        
        if(index< arr.size() and level==arr[index].first){
            
            TreeNode* root=new TreeNode(arr[index].second);
            index++;
            root->left=helper(arr, level+1);
            root->right= helper(arr, level+1);
            return root;
        }else{
            return NULL;
        }
        
       
    }
    TreeNode* recoverFromPreorder(string str) {
        
     
        int i=0;
        
        vector<pair<int,int>> arr;
        
        while(i<str.size()){
            
            int count=0;
            string str2;
            
            while(i<str.size() and str[i]=='-'){
                
             count++;  
                i++;
            }
            
            while(i<str.size() and str[i] !='-'){
                str2+=str[i];
                i++;
            }
            
            arr.push_back({count, stoi(str2)});
            
        }
        
        
//     for(int i=0; i<arr.size();i++){
        
//         cout<<arr[i].first<<" "<<arr[i].second<<endl;
//     }
        
    
        
        
    return helper(arr, 0);
        
     
        
        
    }
};