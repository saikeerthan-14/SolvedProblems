class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<pair<int, int>>v = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int n = h.size(), m = h[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 1e9));
        int ans = 0;
        diff[0][0] = 0;
        pq.push({0, 0, 0});
        while(!pq.empty()) {
            vector<int> t = pq.top();
            pq.pop();
            if(t[1]==n-1 && t[2]==m-1) {
                ans = t[0];
                break;
            }
            for(int i=0;i<4;i++) {
                int nr = t[1] + v[i].first;
                int nc = t[2] + v[i].second;
                if(nr < 0 || nr == n || nc < 0 || nc == m)
                    continue;
            
                int nd = max(t[0], abs(h[nr][nc] - h[t[1]][t[2]]));
            
                if(nd < diff[nr][nc]) {
                    diff[nr][nc] = nd;
                    pq.push({nd, nr, nc});
                }                
            }
        }
        return ans;
        
    }
};