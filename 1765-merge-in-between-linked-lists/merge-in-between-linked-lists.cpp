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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode();
        dummy->next = list1;
        
        ListNode* temp = dummy;
        for (int i = 0; i < a; ++i) {
            temp=temp->next;
        }
        
        ListNode* last = temp;
        for (int i = a; i <= b + 1; ++i) {
            last = last->next;
        }
        
        ListNode* temp1 = list2;
        while (temp1->next != NULL) {
             temp1 = temp1->next;
        }
        
        temp->next = list2;
        temp1->next = last;
        
        return list1;
    }
};