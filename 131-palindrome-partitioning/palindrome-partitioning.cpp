class Solution {
public:
    bool isPalin(string& s, int st, int en) {
        while(st<en) {
            if(s[st++] != s[en--]) return false;
        }
        return true;
    }

    void helper(string &s, vector<vector<string>>& ans, vector<string>& ds, int idx, int N) {
        if(idx == N) {
            if(ds.size()) ans.push_back(ds);
            return;
        }

        for(int i=idx; i<N;i++) {
            if(isPalin(s, idx, i)) {
                ds.push_back(s.substr(idx, i-idx+1));
                helper(s, ans, ds, i+1, N);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        helper(s, ans, ds, 0, s.size());
        return ans;
    }
};