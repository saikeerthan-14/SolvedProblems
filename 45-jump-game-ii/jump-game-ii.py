class Solution:
    def jump(self, nums: List[int]) -> int:
        i=j=ans=0
        n = len(nums)

        while j<n-1:
            maxi_ = 0
            for k in range(i, j+1):
                maxi_ = max(maxi_, k+nums[k])
            i = j+1
            j = maxi_
            ans += 1 
        return ans