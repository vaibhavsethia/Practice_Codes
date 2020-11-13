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
    ListNode* Reverse(ListNode* head){
        ListNode* Curr = head;
        ListNode* Next = NULL;
        ListNode* Prev = NULL;
        
        while(Curr != NULL){
            Next = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }
        
        return Prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL || m == n){
            return head;
        }
        
        ListNode* Start = NULL, *StartPrev = NULL; 
        ListNode* End = NULL, *EndNext = NULL; 

        int i = 1; 
        ListNode* Temp = head; 

        while (Temp && i <= n) { 
            if (i < m){
                StartPrev = Temp; 
            }
            if (i == m){
              Start = Temp; 
            }
            if (i == n) { 
                End = Temp; 
                EndNext = Temp->next; 
            } 

            Temp = Temp->next; 
            i++; 
        } 

        End->next = NULL; 

        End = Reverse(Start); 

        if (StartPrev){
            StartPrev->next = End; 
        } else{
            head = End; 
        }
            
        Start->next = EndNext;
        
        return head; 
    }
};