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
    ListNode* reverse(ListNode* head) {
        ListNode* dummy= NULL;
        while(head!=NULL) {
            ListNode* n = head->next;
            head->next=dummy;
            dummy=head;
            head=n;
        }
        return dummy;
    }

    bool isPalindrome(ListNode* h1) {
        if(h1->next==NULL) return true;
        ListNode *s = h1, *f = h1;
        while(f->next !=NULL && f->next->next!=NULL) {
            s = s->next;
            f = f->next->next;
        }
        ListNode* h2 = reverse(s->next);
        s->next = NULL;
        while(h1!=NULL && h2!=NULL) {
            if(h1->val != h2->val) return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
};