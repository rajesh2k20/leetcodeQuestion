/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*  reverse(ListNode* node,  ListNode* right){
        
        if(node== right){
            
            return node;
        }
        
        ListNode* nextNode= node->next;
        ListNode*  newhead= reverse(node->next, right);
        node->next= nextNode->next;
        nextNode->next=node;
        return newhead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
     int size=0;
      ListNode* node= head;
       ListNode* leftnode=NULL;
    ListNode* rightnode= NULL;
    ListNode* leftprevious=NULL;  
      while(node !=NULL){
          size++;
          if(size== left-1){
              leftprevious=node;
          }
          if(size==left){
              leftnode= node;
          }
          if(size==right){
              rightnode=node;
          }
          
          node= node->next;
          
      }
        
     ListNode* newhead=reverse(leftnode, rightnode);
      if(leftprevious==NULL){
          
          return newhead;
      }else{
          
          leftprevious->next= newhead;
          return head;
      }
    }
    
};