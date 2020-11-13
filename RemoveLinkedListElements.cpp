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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return NULL;
        }
        
        while(head && head->val == val){
            head = head->next;
            if(head == NULL){
                return head;
            }
        }
        
        ListNode* Temp = head;
        ListNode* Prev = NULL;
        
        while(Temp){
            if(Temp->val == val){
                Prev->next = Temp->next;
                Temp = Prev->next;
            } else{
                Prev = Temp;
                Temp = Temp->next;
            }
        }
        
        return head;
    }
};