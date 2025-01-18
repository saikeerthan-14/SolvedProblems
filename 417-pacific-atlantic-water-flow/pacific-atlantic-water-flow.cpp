class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& vis, vector<vector<int>>& h) {
        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, -1, 0, 1};
        
        int m = h.size();
        int n = h[0].size();

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            // cout<<"("<<i<<", "<<j<<") - ";
            vis[i][j] = 1;
            for(int k =0;k<4;k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=m || ni<0 || nj>=n || nj<0 || vis[ni][nj]) continue;
                if(h[ni][nj]>= h[i][j]) {
                    q.push({ni, nj});
                    // cout<<"("<<ni<<", "<<nj<<") ";
                    
                }
            }
            // cout<<endl;
        }
        // cout<<"===\n";
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size();
        vector<vector<int>> atl(m, vector<int>(n, 0)), pac(m, vector<int>(n, 0));

        queue<pair<int, int>> q;

        for(int i=0;i<m;i++) {
            q.push({i, 0});
        }
        for(int i=0;i<n;i++) {
            q.push({0, i});
        }
        bfs(q, pac, h);

        for(int i=0;i<m;i++) {
            q.push({i, n-1});
        }
        for(int i=0;i<n;i++) {
            q.push({m-1, i});
        }
        bfs(q, atl, h);

        vector<vector<int>> ans;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n; j++) {
                if(atl[i][j] == 1 && pac[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};