class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_val = float('-inf')
        pref, suff = 1, 1
        for i in range(len(nums)):
            if pref == 0:
                pref = 1
            if suff == 0:
                suff = 1
            pref *= nums[i]
            suff *= nums[len(nums) - i - 1]
            max_val = max(max_val, max(pref, suff))
        
        return max_val
        
        