class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp) {
            // Step 1: Find the kth node from temp
            ListNode* kthNode = temp;

            for (int i = 1; i < k && kthNode; i++) {
                kthNode = kthNode->next;
            }

            // Step 2: If fewer than k nodes remain, keep them unchanged
            if (kthNode == nullptr) {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }

            // Step 3: Save the start of the next group
            ListNode* nextNode = kthNode->next;

            // Step 4: Detach the current group
            kthNode->next = nullptr;

            // Step 5: Reverse the current group
            // kthNode becomes its new head
            // temp becomes its new tail
            reverse(temp);

            // Step 6: Attach the reversed group
            if (prevLast == nullptr) {
                // First group: update the list's head
                head = kthNode;
            } else {
                // Other groups: connect the previous group's tail
                // to the current group's new head
                prevLast->next = kthNode;
            }

            // Step 7: Store the current group's tail
            // so it can connect to the next reversed group
            prevLast = temp;

            // Step 8: Move to the next group
            temp = nextNode;
        }

        return head;
    }
};