class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int ans = 0, cnt=0;
        vector<pair<int, int>> v={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cnt = 0;
                if(grid[i][j]==1) {
                    cnt++;
                    q.push({i, j});
                    grid[i][j] = -1;
                    while(!q.empty()) {
                        pair<int, int> top = q.front();
                        q.pop();
                        for(int l=0;l<4;l++) {
                            int x = top.first + v[l].first;
                            int y = top.second + v[l].second;
                            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1) {
                                cnt++;
                                q.push({x, y});
                                grid[x][y] = -1;
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
    
};

