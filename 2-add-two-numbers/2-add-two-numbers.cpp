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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0, s;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* d = new ListNode(-1);
        ListNode* tmp = d;
        while(l1 && l2) {
            s = l1->val + l2->val + c;
            c = s/10;
            d->next = new ListNode(s%10);
            l1 = l1->next;
            l2 = l2->next;
            d = d->next;
        }
        while(l1) {
            s = l1->val + c;
            c = s/10;
            d->next = new ListNode(s%10);
            l1 = l1->next;
            d = d->next;
        }
        while(l2) {
            s = l2->val + c;
            c = s/10;
            d->next = new ListNode(s%10);
            l2 = l2->next;
            d = d->next;
        }
        if(c) d->next = new ListNode(c);
        return tmp->next;
    }
};