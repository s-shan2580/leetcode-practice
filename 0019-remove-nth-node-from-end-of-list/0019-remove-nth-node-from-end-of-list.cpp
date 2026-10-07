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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == nullptr || head->next == nullptr){
             return nullptr;
        
        }

        ListNode* i = head;
        ListNode* j = head;
        int count = 0;

        while( i->next!= nullptr){
            i=i->next;
            count++;
            if(count>n) j=j->next;
        }

        if(count+1 == n){
            head = head->next;
            return head;
        } 
        ListNode* temp = j->next;
        j->next = j->next->next;
        delete temp;

        return head;
    }
};