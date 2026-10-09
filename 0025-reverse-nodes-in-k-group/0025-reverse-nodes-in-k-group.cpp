class Solution {
public:
    ListNode* getKthNode(ListNode* temp, int k) {
        k--;

        while (temp && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

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
            ListNode* kthNode = getKthNode(temp, k);

            // Fewer than k nodes remain
            if (kthNode == nullptr) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }

            // Save the start of the next group
            ListNode* nextNode = kthNode->next;

            // Detach the current group
            kthNode->next = nullptr;

            // Reverse the detached group
            reverse(temp);

            // Update the head for the first group
            if (temp == head) {
                head = kthNode;
            } else {
                // Connect the previous group to this group
                prevLast->next = kthNode;
            }

            // The original first node is now the last node
            prevLast = temp;

            // Move to the next group
            temp = nextNode;
        }

        return head;
    }
    
};
