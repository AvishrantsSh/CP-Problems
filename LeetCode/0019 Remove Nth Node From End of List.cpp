class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head -> next)
            return head->next;
        
        ListNode *ptr=head, *tmp = head;
        while(n--) tmp = tmp->next;
        if(tmp == nullptr) return head->next;
        for(; tmp->next; tmp = tmp->next, ptr=ptr->next){}        
        ptr->next = ptr->next->next;
        return head;
    }
};