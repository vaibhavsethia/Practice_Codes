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
        if(head==NULL){
            return head;
        }
        
		ListNode *Prev, *Curr, *Dummy = new ListNode(0);
        
        Dummy->next = head;
        Prev = Dummy;
        Curr = head;
        
		while(Curr != NULL){
            while(Curr->next != NULL && Curr->val==Curr->next->val) Curr = Curr->next;
            if(Prev->next != Curr) Prev->next = Curr->next;
            else Prev = Curr;
            Curr = Curr->next;
        }
        return Dummy->next;
    }
};