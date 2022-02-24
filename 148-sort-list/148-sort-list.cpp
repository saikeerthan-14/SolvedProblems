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
    ListNode* sortList(ListNode* head) {
        ListNode *s = head, *f = head, *tmp = NULL;
        if(head==NULL || head->next==NULL) return head;
        while(f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
        }
        tmp = s->next;
        s->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(tmp);
        
        return merge(l1, l2);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(l1 && l2) {
            if(l1->val<=l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1) {
            curr->next = l1;
        }
        if(l2) curr->next = l2;
        return dummy->next;
    }
};