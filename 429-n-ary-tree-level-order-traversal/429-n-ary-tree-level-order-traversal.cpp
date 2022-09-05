/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root==NULL){
            return {};
        }
        
        
        queue<Node*> q;
        
        q.push(root);
        
        vector<vector<int>> arr;
        
        while(q.size()>0){
            
            int size=q.size();
            
            vector<int> d;
            
            while(size--){
                
                Node* curr= q.front();
                d.push_back(curr->val);
                q.pop();
                
                for(auto  x: curr->children){
                    
                    q.push(x);
                }
            }
            arr.push_back(d);
        }
        
        return arr;
    }
};