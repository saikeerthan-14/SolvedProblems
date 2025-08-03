def helper(ans, n, k, temp, st):
    # print(temp)
    if n==0:
        ans.append(temp)
        return
    if st - k >= 0:
        helper(ans, n-1, k, temp*10 + st-k, st-k)
    if st + k <=9:
        helper(ans, n-1, k, temp *10 + st+k, st+k)
    return

class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        ans = []
        for i in range(1, 10):
            # print(i)
            if k:
                helper(ans, n-1, k, i, i)
            else:
                ans.append(int(str(i)*n))
            # print(ans)
        return ans