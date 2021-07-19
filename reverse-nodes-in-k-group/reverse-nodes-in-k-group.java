/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        int count = 0;
        ListNode temp = new ListNode();
        temp.next = head;
        ListNode prev = temp, curr = temp, next = temp;
        while(curr.next!=null) {
            count++;
            curr = curr.next;
        }
        if(count<k) return head;
        while(count>=k) {
            curr = prev.next;
            next = curr.next;
            for(int i=1;i<k;i++) {
                curr.next = next.next;
                next.next = prev.next;
                prev.next = next;
                next = curr.next;
            }
            prev = curr;
            count -= k;
        }
        return temp.next;
    }
}