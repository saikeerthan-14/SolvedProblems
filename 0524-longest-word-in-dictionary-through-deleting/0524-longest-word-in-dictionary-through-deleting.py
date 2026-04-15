from collections import defaultdict 
import bisect
class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        pos = defaultdict(list)

        for i, ch in enumerate(s):
            pos[ch].append(i)
        # print(pos)
        dictionary.sort(key = lambda x: (-len(x), x))
        # print(dictionary)

        for word in dictionary:
            prev_idx = -1
            curr_idx = 0
            # ans = ""
            # print(word)
            for ch in word:
                if ch not in pos:
                    break
                idxs = pos[ch]
                curr_idx = bisect.bisect_right(idxs, prev_idx)
                if curr_idx >= len(idxs):
                    break
                else:
                    prev_idx = idxs[curr_idx]
                # print(ch, pos[ch])
                # print(prev_idx, curr_idx)
                
            else:
                # ans += ch
            # print(ans)
            # if ans==word:
                return word
            # print("=======")


        return ""