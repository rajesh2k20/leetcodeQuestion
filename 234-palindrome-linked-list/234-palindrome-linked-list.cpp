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
    bool checkpalidrom(ListNode* head, ListNode* & pointer){
        
        if(head==NULL){
            return  true;
        }
        
        bool currans=checkpalidrom(head->next,pointer);
        if(currans==false){
            return currans;
        }
        if(head->val==pointer->val){
          pointer=pointer->next;
            return true;
        }else{
            return false;
        }
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode* pointer=head;
        
        return checkpalidrom(head, pointer);
        
    }
};