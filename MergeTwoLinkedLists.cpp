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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL){
      return l2;
    }
    if(l2==NULL){
      return l1;
    }
    
    
   ListNode* Temp = l1;
   ListNode* Prev = NULL;
    
    
    while(Temp != NULL && l2 != NULL){
        
        if(l2->val <= Temp->val){
           ListNode* Dummy = new ListNode(l2->val);
           
          if(Prev == NULL){
            Dummy->next = Temp;
            l1 = Dummy;   
          } else{
            Prev->next = Dummy;
            Dummy->next = Temp;
          }

          Prev = Dummy;
          l2 = l2->next;
        } else{  
            Prev = Temp;
            Temp = Temp->next;
        }  
    }

    if(l2 != NULL){
      Prev->next=l2;
    }
    return l1;
  }
};