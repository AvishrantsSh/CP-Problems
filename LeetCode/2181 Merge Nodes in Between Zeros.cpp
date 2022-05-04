class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head->next) return nullptr;
        
        ListNode *hptr = head, *ptr = head;
        int sum = 0;
        while((head = head->next)){
            if(head->val == 0){
                ptr = ptr->next;
                ptr->val = sum;
                sum = 0;
                continue;
            }
            sum += head->val;
        }
        ptr->next=nullptr;
        return hptr->next;
    }
};