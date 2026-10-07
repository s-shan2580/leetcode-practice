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
    ListNode* mergeLists(ListNode* a, ListNode* b){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(a!=nullptr && b!=nullptr){
            if(a->val<=b->val){
                curr->next=a;
                a=a->next;
            }
            else{
                curr->next= b;
                b= b->next;
            }
            curr=curr->next;
        }

        if(a!=nullptr){
            curr->next = a;
        } 
        else{
            curr->next = b;
        }

        ListNode* newhead= dummy->next;
        delete dummy;

        return newhead;

    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next=nullptr;

        ListNode* head1= sortList(head);
        ListNode* head2= sortList(slow);

        ListNode* mergeHead= mergeLists(head1, head2);

        return mergeHead; 
    }
};