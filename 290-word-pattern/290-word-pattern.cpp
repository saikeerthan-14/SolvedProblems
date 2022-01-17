class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string sa;
        vector<string> v;
        stringstream ss(s);
        while(ss>>sa)
            v.push_back(sa);
        if(v.size()!=pattern.size()) return false;
        unordered_map<char, string> u;
        for(int i=0;i<v.size();i++) {
            if(u.find(pattern[i])!=u.end()) {
                if(u[pattern[i]] != v[i]) return false;
            } else {
                u[pattern[i]] = v[i];
            }
        }
        unordered_map<string, char> u1;
        for(int i=0;i<v.size();i++) {
            if(u1.find(v[i])!=u1.end()) {
                if(u1[v[i]] != pattern[i]) return false;
            } else {
                u1[v[i]] = pattern[i];
            }
        }
        return true;
    }
};