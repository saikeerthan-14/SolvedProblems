class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        if(n==2) return {0, 1};
        vector<int>ans;
        vector<vector<int>>adj(n);
        vector<int>degree(n, 0);

        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(degree[i]==1) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            ans.clear();
            int k = q.size();
            while(k--) {
                int ele = q.front();
                q.pop();
                ans.push_back(ele);
                for(int i=0;i<adj[ele].size();i++) {
                    degree[adj[ele][i]]--;
                    if(degree[adj[ele][i]]==1) {
                        q.push(adj[ele][i]);
                    };
                }
            }
        }
        return ans;
    }
};
