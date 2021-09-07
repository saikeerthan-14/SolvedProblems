class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r = m.size(), c = m[0].size();
        int i = 0, j = c-1;
        while(i<r && j>=0) {
            if(m[i][j] == t) return true;
            else if(m[i][j]<t) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};