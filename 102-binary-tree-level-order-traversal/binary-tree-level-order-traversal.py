# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        l = []
        ans = []
        if root==None:
            return []
        l.append(root)
        while len(l)!=0:
            p = len(l)
            z = []
            while p:
                p-=1
                k = l[0]
                z.append(k.val)
                l.pop(0)
                if k.left:
                    l.append(k.left)
                if k.right:
                    l.append(k.right)
            ans.append(z)
        return ans

        