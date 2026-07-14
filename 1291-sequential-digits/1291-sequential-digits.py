class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        len_low, len_high = 0, 0
        low_copy, high_copy = low, high
        while low_copy:
            len_low += 1
            low_copy //= 10
        while high_copy:
            len_high += 1
            high_copy //= 10
        # print(len_low, len_high)
        
        for i in range(len_low, min(10, len_high+1)):
            # z = len(ans)
            val = int("".join([str(x) for x in range(1,10)][:i]))
            while val < low and val%10!=0:
                val += int("1"*i)
            # print(val)
            while val <= high and val%10!=0:
                ans.append(val)
                val += int("1"*i)
            # print(i, ans[z:])
        return ans