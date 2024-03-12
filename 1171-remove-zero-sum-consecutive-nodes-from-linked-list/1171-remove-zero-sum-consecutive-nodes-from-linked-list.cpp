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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> u;
        int sum = 0;
        ListNode* dummy = new ListNode(-1002);
        dummy->next = head;
        u[0] = dummy;
        while(head!=NULL) {
            sum += head->val;
            if(u.find(sum)==u.end()) {
                u[sum] = head;
            }
            else {
                ListNode* s = u[sum];
                ListNode* t = s->next;
                int q = sum;
                while(t!=head) {
                    q += t->val;
                    u.erase(q);
                    t = t->next;
                }
                s->next = head->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};