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
        ListNode *res = nullptr;
        ListNode *ptr = nullptr;
        while(l1 || l2){
            if (res == nullptr){
                res = new ListNode();
                ptr = res;
            }
            else{
                res->next = new ListNode(res->val > 9);
                res->val = res->val % 10;
                res = res->next;
            }
            res->val +=  (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            l1 = l1 ? l1->next : nullptr, l2 = l2 ? l2->next : nullptr;
        }
        
        if(res->val > 9){
            res->next = new ListNode(res->val > 9);
            res->val = res->val % 10;
        }
        return ptr;
    }
};