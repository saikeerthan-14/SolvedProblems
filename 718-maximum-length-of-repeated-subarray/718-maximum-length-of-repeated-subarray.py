class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        if len(nums1) < len(nums2): 
            return self.findLength(nums2, nums1)  # Make sure len(nums1) > len(nums2) to optimize time & space

        def computeKMP(pattern):
            n = len(pattern)
            lps = [0] * n
            j = 0
            for i in range(1, n):
                while j > 0 and pattern[i] != pattern[j]: j = lps[j - 1]
                if pattern[i] == pattern[j]: j += 1
                lps[i] = j
            return lps

        ans = 0
        while len(nums2) > ans:
            lps = computeKMP(nums2)
            j = 0  # pattern pointer
            for i in range(len(nums1)):
                while j > 0 and nums1[i] != nums2[j]: j = lps[j - 1]
                if nums1[i] == nums2[j]: j += 1
                ans = max(ans, j)  # update longest matching between prefix of P and substring of S so far
                if j == len(nums2):  # if P was found in S
                    j = lps[j - 1]
            del nums2[0]
        return ans
