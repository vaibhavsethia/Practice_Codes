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
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head){
            return vector<int>{};
        }
        
        if(!head->next){
            return vector<int>{0};
        }
        
        
        ListNode* Element = head;
        vector<int> Sol;
        
        while(Element){
            ListNode* GreaterElement = Element;
            
            while(GreaterElement){
                if(GreaterElement->val > Element->val){
                    break;
                }
                GreaterElement = GreaterElement->next;
            }
            
            Sol.push_back(GreaterElement?GreaterElement->val:0);
            Element = Element->next;
        }
        
        return Sol;
    }
};