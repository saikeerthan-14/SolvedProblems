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
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* dummy= NULL;
//         while(head!=NULL) {
//             ListNode* n = head->next;
//             head->next=dummy;
//             dummy=head;
//             head=n;
//         }
//         return dummy;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* nex = head->next;
        while(head!=NULL) {
            head->next = prev;
            prev = head;
            head = nex;
            if(head)
                nex = head->next;
        }
        return prev;
    }
};