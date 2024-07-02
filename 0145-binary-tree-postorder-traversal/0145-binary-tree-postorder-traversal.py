# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

    
class Solution:
    def helper(k, root, ans):
        if root==None:
            return
        k.helper(root.left, ans)
        k.helper(root.right, ans)
        ans.append(root.val)
    
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        
        self.helper(root, ans)
        return ans
