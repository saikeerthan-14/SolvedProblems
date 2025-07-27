class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i, j = 0, 0
        d = {}
        ans = 0
        while j<len(s):
            if s[j] in d: 
                i = max(i, d[s[j]] + 1)
            ans = max(ans, j-i+1)
            d[s[j]] = j
            j+=1
        return ans
