class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nxt = curr->next;   // 1. save the rest of the list
            curr->next = prev;            // 2. flip the arrow
            prev = curr;                  // 3. move prev forward
            curr = nxt;                   // 4. move curr forward
        }

        return prev;                      // new head
    }
};