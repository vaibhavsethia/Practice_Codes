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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return NULL;
        }
        
        ListNode* Ptr1 = head;
        ListNode* Ptr2 = head->next;
        
        while(Ptr2){
            if(Ptr2->val == Ptr1->val){
                Ptr2 = Ptr2->next;
            } else{
                Ptr1->next = Ptr2;
                Ptr1 = Ptr2;
                Ptr2 = Ptr2->next;
            }
        }
        Ptr1->next = Ptr2;
        
        return head;
    }
};