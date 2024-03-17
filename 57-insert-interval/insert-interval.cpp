class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int N = intervals.size(), i=0;
        vector<vector<int>> answer;
        while (i < N && intervals[i][1] < newInterval[0]) {
            answer.push_back(intervals[i++]);
        }
        
        while (i < N && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        answer.push_back(newInterval);
        while (i < N) {
            answer.push_back(intervals[i++]);
        }
        return answer;
    }
};