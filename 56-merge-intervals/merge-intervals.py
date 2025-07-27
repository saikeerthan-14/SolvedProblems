class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        i=0
        print(intervals)
        for j in range(1, len(intervals)):
            if intervals[i][1]>=intervals[j][0]:
                intervals[i][1] = max(intervals[i][1], intervals[j][1])
            else:
                i+=1
                intervals[i] = intervals[j]
        return intervals[:i+1]
        