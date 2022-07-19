class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        if(numRows == 1) {
            return ans;
        }
        for(int i=2;i<=numRows;i++) {
            vector<int> v = {1};
            for(int j=1;j<ans[i-2].size();j++) {
                v.push_back(ans[i-2][j-1] + ans[i-2][j]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};