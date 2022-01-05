class Solution {
public:
    bool isPalin(string s, int l, int h) {
        while(l<=h) {
            if(s[l++]!=s[h--]) return false;
        }
        return true;
    }
    void divide(int idx, string s, vector<string>part, vector<vector<string>>&ans) {
        if(idx==s.size()) {
            ans.push_back(part);
            return;
        }
        for(int i=idx;i<s.size();i++) {
            if(isPalin(s, idx, i)) {
                part.push_back(s.substr(idx,i+1-idx));
                divide(i+1, s, part, ans);
                part.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        divide(0, s, {}, ans);
        return ans;
    }
};