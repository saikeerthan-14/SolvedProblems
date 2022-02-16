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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
//         ListNode* d = new ListNode(-1);
        
//         ListNode *prev = d, *curr = head, *nn = head->next;
//         while(nn!=NULL && nn->next!=NULL) {
//             prev->next = curr;
//             prev = prev->next;
//             curr = nn->next;
//             nn->next = prev;
//             nn = curr->next;
//         }
//         return d->next;
        ListNode* temp = head->next;
        ListNode* prev = NULL;
        while(head && head->next ) {
            ListNode* n = head->next;
            ListNode* nn = head->next->next;
            
            head->next = nn;
            n->next = head;
            if(prev) {
                prev->next = n;
            }
            prev = head;
            head = head->next;
            
        }
        
        return temp;
    }
};