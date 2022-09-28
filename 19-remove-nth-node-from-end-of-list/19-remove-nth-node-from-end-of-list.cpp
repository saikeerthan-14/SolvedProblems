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
        // int c = 0;
        ListNode *s=head, *f=head;
        while(n>0 && f->next!=nullptr) {
            f = f->next;
            n--;
        }
        if(n){
            return head->next;
        }
        cout<<n<<endl;
        while(f->next!=nullptr) {
            s = s->next;
            f = f->next;
        }
        s->next = s->next->next;
        return head;
            
    }
};