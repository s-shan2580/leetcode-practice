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
    ListNode* reverseList(ListNode* head) {
        
        if(head==nullptr) return head;

        ListNode* prev= nullptr;
        ListNode* curr= head;
        ListNode* temp= head;

        while(curr != nullptr){
            temp = curr;
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            
        }

        return prev;
    }
};