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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode *d = new ListNode();
        d->next = head;
        ListNode *prev = d, *curr = d, *nex = d;
        int count = 0;
        while(curr->next!=nullptr) {
            curr = curr->next;
            count++;
        }
        while(count>=k) {
            curr = prev->next;
            nex = curr->next;
            for(int i=1;i<k;i++) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            count -= k;
        }
        return d->next;
    }
};