// Approach - 1 (using set)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> set;
        while(head!= nullptr){
            if(set.find(head) == set.end()){
                set.insert(head);
                head = head->next;
                continue;
            }
            return head;
        }
        return nullptr;
    }
};

// Approach - 2 (Floyd's Cycle-Finding Algorithm)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};