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

    int getSize(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }

    ListNode* rev(ListNode* head) {
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

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;

        int n = getSize(head);
        k = k % n;

        if(k == 0) return head;

        ListNode* temp = rev(head);
        ListNode* head1 = temp;

        for(int i=1; i<k && temp; i++){
            temp = temp->next;
        }

        ListNode* nxtnode = temp->next;
        temp->next = nullptr;

        ListNode* newHead = rev(head1);
        head1->next = rev(nxtnode);

        return newHead;

    }
};