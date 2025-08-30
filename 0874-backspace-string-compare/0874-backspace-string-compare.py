class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def add(st):
            j = -1
            n = len(st)
            for i in st:
                if i=="#":
                    if j>=0:
                        j-=1
                else:
                    j += 1
                    st[j] = i
            return st[:j+1] if j>=0 else ""
        # print(add(list(s)))
        # print(add(list(t)))
        return add(list(s)) == add(list(t))