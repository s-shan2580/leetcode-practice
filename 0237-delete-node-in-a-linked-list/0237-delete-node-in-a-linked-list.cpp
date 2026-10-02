/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        while(temp->next != nullptr){
            temp->val = temp->next->val;
            temp = temp->next;
        }

    
        ListNode* prev = node;
        while(prev->next->next != nullptr){
            prev = prev->next;
        }
        ListNode* last = prev->next;
        prev->next = nullptr;
        delete last;





    }
};