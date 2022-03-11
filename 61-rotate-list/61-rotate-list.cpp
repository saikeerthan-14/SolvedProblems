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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int cnt =1;
        ListNode *t=head;
        while(t->next!=nullptr) {
            t = t->next;
            cnt++;
        }
        k = k%cnt;
        t->next = head;
        while(cnt-k-1>0) {
            head = head->next;
            cnt--;
        }
        t = head->next;
        head->next = nullptr;
        return t;
    }
};