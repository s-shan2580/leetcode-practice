class Solution {
public:
    void deleteNode(ListNode* node) {
        // Step 1: Target the immediate next node
        ListNode* nextNode = node->next;

        // Step 2: Overwrite current node's value with next node's value
        node->val = nextNode->val;

        // Step 3: Bypass the next node
        node->next = nextNode->next;

        // Step 4: Clean up heap memory
        delete nextNode;
    }
};