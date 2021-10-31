/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *curr = head;
        stack<Node*>s;
        while(!s.empty() || curr!=nullptr) {
            if(curr->child!=NULL) {
                if(curr->next!=NULL) {
                    s.push(curr->next);
                }
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
            } else {
                if(curr->next==NULL && !s.empty()) {
                    curr->next = s.top();
                    s.pop();
                    curr->next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};