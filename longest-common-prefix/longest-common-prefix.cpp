class Solution {
    bool check(vector<string>& strs, int i) {
        char c = strs[0][i];
        for(int j=1;j<strs.size();j++) {
            if(strs[j][i] != c) return false;
        }
        return true;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minSize = 201, n = strs.size();
        string ans = "";
        for(string &s: strs) {
            if(minSize>s.size()) {
                minSize = s.size();
            }
        }
        for(int i=0;i<minSize;i++) {
            if(check(strs, i)){
                ans.push_back(strs[0][i]);
            } else {
                return ans;
            }
        }
        return ans;
    }
};