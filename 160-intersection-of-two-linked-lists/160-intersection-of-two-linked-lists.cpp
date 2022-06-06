class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // create node temp1 initially pointing headA
        ListNode* temp1 = headA;
        // create node temp2 initially pointing headB
        ListNode* temp2 = headB;
        // initialize length of both ll with 0
        int l1 = 0, l2 = 0;
        // now our aim is to calculate length of both ll and store them in l1 and l2 respectively
        // for l1, keep moving till the end of the ll A
        while(temp1 != NULL){
            // increment l1 by 1 for each iteration
            l1++;
            // increment temp1 with the help of temp1 -> next
            temp1 = temp1 -> next;
        }
        // for l2, keep moving till the end of ll B
        while(temp2 != NULL){
            // increment l2 by 1 for each iteration
            l2++;
            // increment temp2 with the help of temp2 -> next
            temp2 = temp2 -> next;
        }
        // till here we have got the length of both strings stored in l1 and l2 respectively
        // but our temp1 and temp2, will be pointing the last node of ll's
        // so reset temp1 and temp2
        temp1 = headA;
        temp2 = headB;
        // if length of ll A is greater than length of ll B 
        if(l1 > l2)
            // increment the pointer of greater ll by the difference of length between those ll's
            for(int i = 0; i < l1 - l2; i++)
                temp1 = temp1 -> next;
        // if length of ll B is greater than length of ll A
        else if(l2 > l1)
            // increment the pointer of greater ll by the difference of length between those ll's
            for(int i = 0; i < l2 - l1; i++)
                temp2 = temp2 -> next;
        // now keep iterating till both pointer temp1 and temp2 intersects with each other
        // intersection of temp1 and temp2 will represent the node present at the intersection of ll's
        // if they do not intersect till end means there is no intersection between those ll's,
        // in that case temp1 and temp2 will be pointing NULL
        while(temp1 != temp2){
            // increment temp1
            temp1 = temp1 -> next;
            // increment temp2
            temp2 = temp2 -> next;
        }
        // here, both temp1 and temp2 will be our ans (pointer at which intersection happend)
        // thus, return any of them, here I am returning temp1
        return temp1;
    }
};
