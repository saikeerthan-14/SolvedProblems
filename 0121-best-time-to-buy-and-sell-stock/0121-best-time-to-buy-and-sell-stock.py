class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        m = prices[0]
        for i in prices:
            m = min(m, i)
            ans = max(ans, i-m)
        return ans