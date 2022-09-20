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
    int getSize(ListNode * head){
        
        int size=0;
        
         ListNode* temp=head;
        
        while(temp !=NULL){
            
            temp=temp->next;
            size++;
        }
        
        return size;
        
    }
    ListNode* reverse(ListNode* head){
        
        ListNode* curr=head;
        ListNode* pre=NULL;
        
        while(curr!=NULL){
            
            ListNode* temp= curr->next;
            
            curr->next=pre;
            
            pre=curr;
            curr=temp;
            
        }
        
        return pre;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL){
            return 0;
        }
       
      int size= getSize(head);
      k= k%(size);
        
     int d= size-k;
        
     ListNode* temp=head;
        
     while(d>1){
        
        temp= temp->next;
         d--;
     }
        
      
     
     ListNode* h1= reverse(temp->next);
     temp->next=NULL;
     ListNode* h2= reverse(head);
     head->next=h1;
      return reverse(h2);
        
    }
};