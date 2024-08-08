class Solution {
public:
    bool isValid(int r, int c, int m, int n) {
        if(r<0 || c<0 || r>=m || c>=n) return false;
        return true;
    } 

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int t = rows*cols;
        int i = rStart, j = cStart, step = 1, rs=111, ds=111, ls=111, us=111;
        ans.push_back({i, j});
        while(ans.size()!=t) {
            rs = ds = step;
            // right
            while(rs--) {
                j++;
                if(isValid(i, j, rows, cols)) {
                    ans.push_back({i, j});
                }
            }
            
            // down
            while(ds--) {
                i++;
                if(isValid(i, j, rows, cols)) {
                    ans.push_back({i, j});
                }
            }
            step++;
            ls = us = step;

            // left
            while(ls--) {
                j--;
                if(isValid(i, j, rows, cols)) {
                    ans.push_back({i, j});
                }
            }
            // up
            while(us--) {
                i--;
                if(isValid(i, j, rows, cols)) {
                    ans.push_back({i, j});
                }
            }
            step++;
        }
        return ans;
    }
};