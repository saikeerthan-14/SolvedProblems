class Solution {
public:
    int largestIsland(vector<vector<int>>& mat) {
        int ma = 0;
        int cnt = 2, freq;
        unordered_map<int, int>u;
        queue<pair<int, int>>q;
        vector<pair<int, int>> v = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int n = mat.size(), m = mat[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]!=1) continue;
                else if(mat[i][j] == 1) {
                    freq = 1;
                    mat[i][j] = cnt;
                    q.push({i, j});
                    while(!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++) {
                            int x1 = x + v[k].first, y1 = y+v[k].second;
                            if(x1>=0 && x1<n && y1>=0 && y1<m && mat[x1][y1] == 1) {
                                freq++;
                                mat[x1][y1] = cnt;
                                q.push({x1, y1});
                            }
                        }
                    }
                    ma = max(ma, freq);
                    u[cnt] = freq;
                    cnt++;
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) {
                // cout<<mat[i][j]<<" ";
                if(mat[i][j] == 0) {
                    cnt = 0;
                    unordered_set<int> s;
                    for(int k=0;k<4;k++) {
                        int x1 = i + v[k].first, y1 = j+v[k].second;
                        if(x1>=0 && x1<n && y1>=0 && y1<m && mat[x1][y1] > 1) {
                             // cnt += u[mat[x1][y1]];
                            s.insert(mat[x1][y1]);
                            // cout<<"en";
                        }
                    }
                    for(auto l: s) 
                        cnt += u[l];
                    ma = max(cnt+1, ma);
                }
            }
            // cout<<endl;
        }
        return ma;
    }
};