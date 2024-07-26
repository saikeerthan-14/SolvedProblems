class Solution {
public:
    int INM = 100000;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> G(n, vector<int>(n, INM));
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            G[u][v] = G[v][u] = w;
        }
        for(int i=0;i<n;i++) {
            G[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
        int ma = 0, mc = INM;
        for(int i=0;i<n;i++) {
            int cnt = 0;
            for(int j=0;j<n;j++) {
                // if(i==j) G[i][j] = 0;
                // cout<<G[i][j]<<" ";
                if(i!=j && G[i][j]<=distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt<=mc) {
                mc = cnt;
                ma = i;
            }
            // cout<<endl;
            // cout<<cnt<<" count"<<endl; 
            
        }
        return ma;
    }

};