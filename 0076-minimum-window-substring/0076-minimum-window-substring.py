from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ans = len(s)+1, 0, len(s)-1
        mi = len(s)
        d = Counter(t)
        cnt = len(d.keys())
        i, j = 0, 0
        while j < len(s):
            print(i, j)
            if s[j] in d:
                d[s[j]] -= 1
                if d[s[j]] == 0:
                    cnt -= 1
            while i<=j and cnt == 0:
                print(i, j, "==")
                if j-i+1 < ans[0]:
                    ans = (j-i+1, i, j)
                if s[i] in d:
                    if d[s[i]]==0:
                        cnt += 1
                    d[s[i]] += 1
                i += 1
            j += 1
        return "" if ans[0] == len(s) + 1 else s[ans[1]: ans[2]+1]




