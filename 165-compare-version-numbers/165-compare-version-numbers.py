class Solution:
    def compareVersion(self, v1: str, v2: str) -> int:
        p = list(map(int, v1.split(".")))
        q = list(map(int, v2.split(".")))
        i=0
        while i < min(len(p), len(q)):
            if p[i]>q[i]:
                return 1
            elif p[i]<q[i]:
                return -1
            i+=1
        while i<len(p):
            if p[i]>0:
                return 1
            i+=1
        while i<len(q):
            if q[i]>0:
                return -1
            i+=1
        return 0
        