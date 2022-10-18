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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        n++;
        
        ListNode* temp= head;
        
        while(n>0 and temp != NULL){
            n--;
            temp=temp->next;
        }
        
        if(n>0){
            
            return head->next;
        }
        
        ListNode * temp1= head;
        
        while(temp!=NULL){
            
            temp=temp->next;
            temp1=temp1->next;
        }
        
        temp1->next=temp1->next->next;
        
        return head;
        
    }
};