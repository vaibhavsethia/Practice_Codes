/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next){
            return head;
        }
            
        ListNode* Mid = GetMiddle(head);
        ListNode* Left = sortList(head);
        ListNode* Right = sortList(Mid);

        return merge(Left, Right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        
        if(list1) ptr->next = list1;
        else ptr->next = list2;

        return dummyHead.next;
    }

    ListNode* GetMiddle(ListNode* head) {
        ListNode* midPrev = NULL;

        while (head && head->next) {
            midPrev = (midPrev == NULL) ? head : midPrev->next;
            head = head->next->next;
        }

        ListNode* Mid = midPrev->next;
        midPrev->next = NULL;

        return Mid;
    }
};


