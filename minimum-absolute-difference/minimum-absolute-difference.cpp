class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& A) {
        auto [mn, mx] = minmax_element(begin(A), end(A));       // returns iterator to min and max element in A
        int R = *mx - *mn + 1, shift = -*mn, minDiff = INT_MAX, curDiff, prevElement = -R;
        vector<vector<int>> ans;
        vector<bool> seen(R);                                   // used to denote if i is present or not over the remapped range [0, R]
        for(auto c : A) seen[c + shift] = true;                 // mark each element of A as seen after applying shift
        for(int i = 0; i < R; i++)
            if(seen[i]) {
                int a = prevElement - shift, b = i - shift;     // remove the applied shift while pushing into ans array
                curDiff = b - a;
                if(curDiff == minDiff) ans.push_back({a, b});
                else if(curDiff < minDiff) {
                    minDiff = curDiff;
                    ans = {{a, b}};
                }
                prevElement = i;                                // update previous element so we only compare adjacent elements of sorted A
            }
        
        return ans;
    }
};