class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 0) {
                    q.push(make_pair(i, j));
                    ans[i][j] = 0;
                }
            }
        }
        vector<pair<int, int>>adj = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for(int i=0;i<4;i++) {
                int x1 = p.first + adj[i].first;
                int y1 = p.second + adj[i].second;
                if(x1>=0 && y1>=0 && x1<n && y1<m && ans[x1][y1]>ans[x][y]+1) {
                    ans[x1][y1] = ans[x][y] + 1;
                    q.push({x1, y1});
                }
            }
        }
        return ans;
    }
};