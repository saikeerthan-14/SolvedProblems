# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1)
        prev = dummy
        curr = head

        while curr:
            if curr.next and curr.val != curr.next.val:
                prev.next = curr
                curr = curr.next
                prev = prev.next
            elif curr.next is None:
                prev.next = curr
                curr = curr.next
                prev = prev.next
            else:
                p = curr.val
                while curr and curr.val == p:
                    curr = curr.next
        prev.next = curr
        return dummy.next