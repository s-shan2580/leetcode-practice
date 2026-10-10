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
    ListNode* rev(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLastlink = nullptr;

        while(temp){

            ListNode* kthNode = temp;

            for(int i = 1; i<k && kthNode; i++){
                kthNode = kthNode->next;
            }

            if(kthNode==nullptr){
                if(prevLastlink){
                    prevLastlink->next = temp;
                }
                break;
            }

            ListNode* nxtnode = kthNode->next;
            kthNode->next = nullptr;

            rev(temp);

            if(prevLastlink == nullptr){
                head = kthNode;
            }
            else{
                prevLastlink->next = kthNode;
            }

            prevLastlink = temp;
            temp = nxtnode;

        }

        return head;
    }
};