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
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nxt = curr->next; // 1. save the rest of the list
            curr->next = prev;          // 2. flip the arrow
            prev = curr;                // 3. move prev forward
            curr = nxt;                 // 4. move curr forward
        }

        return prev; // new head
    }

    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        //find middle coz we'll reverse the list from middle to end and then compare with first half one by one
        while(fast != nullptr && fast->next != nullptr){  
            slow= slow->next;
            fast= fast->next->next;
        }

        //in case its odd length list, skip the middle and rev from next element to it, coz that mid element wouldnt be comparable and would be single, and how to cjheck mid is in odd length string, just check if fast reached nullptr, then its even length otherwise odd length .

        if(fast != nullptr){
            slow = slow->next;
        }

        ListNode* j = reverseList(slow);
        ListNode* i = head;

        while(j != nullptr){
            if(i->val != j->val){
                return false;
            }

            i= i->next;
            j= j->next;
        }

        return true;

    }
};