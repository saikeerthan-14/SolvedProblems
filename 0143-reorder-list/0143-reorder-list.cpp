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
    void reorderList(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;
        while(f->next!=NULL && f->next->next!=NULL ) {
            s = s->next;
            f = f->next->next;
        }
        f = s->next;
        s->next = NULL;
        ListNode* prev = NULL;
        s = f;
        while(s!=NULL) {
            f = s->next;
            s->next = prev;
            prev = s;
            s = f; 
        }
        s = new ListNode();
        s->next = head;
        f = s;
        while(head!=NULL && prev!=NULL) {
            s->next = head;
            head = head->next;
            s = s->next;
            s->next = prev;
            prev = prev->next;
            s = s->next;
        }
        if(head!=NULL) {
            s->next = head;
        }
        head = f->next;

    }
};