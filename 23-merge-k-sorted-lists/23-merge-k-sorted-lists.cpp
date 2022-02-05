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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head, *p;
        if(l1 -> val <= l2 -> val) {
            head = l1;
            l1 = l1 -> next;
        }
        else {
            head = l2;
            l2 = l2 -> next;
        }
        p = head;
        while(l1 && l2) {
            if(l1 -> val <= l2 -> val) {
                head -> next = l1;
                l1 = l1 -> next;
            }
            else {
                head -> next = l2; 
                l2 = l2 -> next;
            }
            head = head -> next;
        }
        if(!l1) head -> next = l2;
        else if(!l2) head -> next = l1;
        return p;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        // do it for two lists
        for(int i = 1; i < lists.size(); i++) {
             lists[0] = merge2Lists(lists[0], lists[i]);
        }
        return lists[0];
    }
};