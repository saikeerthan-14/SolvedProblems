# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def gameResult(self, head: Optional[ListNode]) -> str:
        even = head
        even_points = 0
        odd_points = 0
        while even:
            odd = even.next
            if even.val > odd.val:
                even_points += 1
            else:
                odd_points += 1
            
            even = odd.next

        if even_points > odd_points:
            return "Even"
        elif odd_points > even_points:
            return "Odd"
        else:
            return "Tie"
            