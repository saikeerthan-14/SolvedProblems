class Solution:
    def longestCommonPrefix(self, word: List[str]) -> str:
        m = min(len(w) for w in word)
        ans = []
        for i in range(m):
            cnt = 0
            for w in word[1:]:
                if w[i] != word[0][i]:
                    return "".join(ans)
            else:
                ans.append(word[0][i])
            
        return "".join(ans)