/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return head;
        Node* t = head, *d, *res;
        while(t!=nullptr) {
            d = t->next;
            t->next = new Node(t->val);
            t->next->next = d;
            t = d;
        }
        t=head;
        while(t!=nullptr) {
            if(t->random!=nullptr)
                t->next->random = t->random->next;
            else
                t->next->random = nullptr;
            t = t->next->next;
        }
        d = head;
        t = d->next;
        res = t;
        while(d->next->next!=nullptr) {
            d->next = d->next->next;
            d=d->next;
            t->next = d->next;
            t = t->next;
        }
        d->next = nullptr;
        t->next = nullptr;
        return res;
    }
};