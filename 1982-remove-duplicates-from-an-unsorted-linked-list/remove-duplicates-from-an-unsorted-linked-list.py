# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        curr = head
        freq = {}
        while curr:
            freq[curr.val] = freq.get(curr.val, 0) + 1
            curr = curr.next

        for i, j in freq.items():
            print(i, j, end = " ")        
        
        dummy = ListNode(0, head)
        prev = dummy

        while head:
            if freq[head.val] > 1:
                prev.next = head.next
                
            else:
                prev = prev.next
            
            head = head.next
        
        return dummy.next