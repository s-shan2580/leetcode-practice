class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {              // phase 1: cycle found
                slow = head;                 // phase 2: reset slow
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;       // both move 1 step now
                }
                return slow;                 // cycle start
            }
        }
        return nullptr;                      // no cycle
    }
};