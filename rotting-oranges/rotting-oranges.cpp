class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        int flag = 1, l =2;
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==l) {
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>>v = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()) {
            int sz = q.size();
            // cout<<sz<<" "<<ans<<endl;
            while(sz--) {
                pair<int, int> p = q.front();
                q.pop();
                for(int i=0;i<4;i++) {
                    int x = p.first + v[i].first;
                    int y = p.second + v[i].second;
                    if(x>=0 && y>=0 &&x<n&&y<m && grid[x][y] == 1) {
                        grid[x][y]++;
                        q.push({x, y});
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }
        return ans>0?ans-1:ans;
    }
};