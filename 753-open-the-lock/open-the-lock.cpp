class Solution {
public:
    int openLock(vector<string>& de, string t) {
        unordered_map<char, pair<char, char>> u;
        u = {
            {'0', {'1', '9'}},
            {'1', {'2', '0'}},
            {'2', {'3', '1'}},
            {'3', {'4', '2'}},
            {'4', {'5', '3'}},
            {'5', {'6', '4'}},
            {'6', {'7', '5'}},
            {'7', {'8', '6'}},
            {'8', {'9', '7'}},
            {'9', {'0', '8'}}
        };

        unordered_set<string> vis(de.begin(), de.end());
        if(vis.find("0000")!=vis.end()) return -1;
        queue<string>q;
        q.push("0000");
        vis.insert("0000");
        int cnt = 0;
        while(!q.empty()) {
            int k = q.size();
            while(k--) {
                string t1 = q.front();
                q.pop();
                if(t==t1) return cnt;
                for(int i=0;i<4;i++) {
                    string ns = t1;
                    ns[i] = u[ns[i]].first;
                    if(vis.find(ns)==vis.end()){
                        q.push(ns);
                        vis.insert(ns);
                    }
                    ns = t1;
                    ns[i] = u[ns[i]].second;
                    if(vis.find(ns)==vis.end()){
                        q.push(ns);
                        vis.insert(ns);
                    }
                }
            }
            cnt++;
        } 
        return -1;

    }
};