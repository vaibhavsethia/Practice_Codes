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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        
        ListNode *Result = new ListNode();
        ListNode *Head = Result;
        ListNode *Prev = NULL;
        int Carry = 0, Sum = 0;
        
        while(l1 || l2 || Carry){
            if (Result == NULL) {
                Result = new ListNode();
                Prev->next = Result;
            }
            
            int First = 0, Second = 0;
            
            if(l1){
                First = l1->val;
            }
            if(l2){
                Second = l2->val;
            }
            
            Sum = First + Second + Carry;
            Carry = Sum / 10;
            
            Result->val = Sum%10;
            l1 = l1? l1->next: NULL;
            l2 = l2? l2->next: NULL;
            
            Prev = Result;
            Result = Result->next;
        }
        
        return Head;
    }
};