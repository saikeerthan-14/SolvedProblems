class Solution:
    def canJump(self, nums: List[int]) -> bool:
        st = 0
        n = len(nums)
        for i in range(n):
            if i<=st:
                st = max(st, i+nums[i])
        return st>=n-1