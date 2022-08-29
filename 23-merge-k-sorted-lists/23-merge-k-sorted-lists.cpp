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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode* head=NULL;
      ListNode * tail=NULL;
      multimap<int, ListNode*>m;
        
      for(int i=0; i<lists.size();i++){
          
          if(lists[i] !=NULL){
              int val= lists[i]->val;
          m.insert({val,lists[i]});
          }
      }
        
        // cout<<m.size()<<endl;
      
     while(m.size()>0){
         
          auto it= m.begin();
          
         ListNode * temp=it->second;
         if(head==NULL){
             
             head=temp;
             tail=temp;
         }else{
             tail->next=temp;
             tail=temp;
         }
          m.erase(it);
         
         if(temp->next !=NULL){
             
             int val= temp->next->val;
             m.insert({val,temp->next});
             // m[val].insert(temp->next);
         }
         
         
         
         
     }
        
        return head;
      
    }
};