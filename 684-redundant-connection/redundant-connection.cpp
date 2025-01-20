class UnionFind {
    vector<int> parent, rank;
    public:
    UnionFind(int size) {
        parent.resize(size+1);
        rank.resize(size+1);
        // rank(size+1){};
        for (int i = 0; i < size+1; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int node) {
        int p = parent[node];
        while(parent[p]!=p) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool union1(int x, int y) {
        int xi = find(x);
        int yi = find(y);
        if(xi==yi) return false;
        else if(rank[xi]<rank[yi]) {
            parent[xi] = yi;
            rank[yi]++;
            return true;
        } else {
            parent[yi] = xi;
            rank[xi]++;
            return true;
        } 
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind* uf = new UnionFind(n);
        for(int i=0;i<n;i++) {
            if(!uf->union1(edges[i][0], edges[i][1])) return edges[i];
        }
        return {};
    }
};