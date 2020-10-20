/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next ){
            return NULL;
        } else if(head->next == head){
            return head;
        }
        
        ListNode* Slow = head;
        ListNode* Fast = head;
        int Flag = false;
        
        while(Fast && Fast->next){
            Slow = Slow->next;
            Fast = Fast->next->next;
            if(Slow == Fast){
                Flag = true;
                break;
            }
        }
        
        if(!Flag){
            return NULL;
        }
        
        Fast=head;
        while(Slow != Fast)
        {
            Fast = Fast->next;
            Slow = Slow->next;
        }
        return Slow;
    }
};