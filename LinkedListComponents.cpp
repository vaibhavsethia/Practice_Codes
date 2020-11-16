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
    int numComponents(ListNode* head, vector<int>& G) {
        if(!head || !G.size()) {
            eturn 0;
        }
        
        unordered_set<int> hash{G.begin(), G.end()};
        ListNode* curr = head;
        int result = 0;
        
        while(curr){
            if(hash.count(curr->val) && (!curr->next || !hash.count(curr->next->val))){
                result++;
            }
            
            curr = curr->next;
        }
        
        return result;
    }
};