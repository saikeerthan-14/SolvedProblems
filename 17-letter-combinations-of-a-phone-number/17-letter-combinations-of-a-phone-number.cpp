class Solution {
public:
    void generate(string &d, vector<string>&v, vector<string> &ans, int idx, string &s) {
        if(d.size()==s.size()) {
            ans.push_back(s);
            return;
        }
        // for(int i=idx;i<d.size();i++) {
            for(int j=0;j<v[d[idx]-'0'].size();j++) {
                s.push_back(v[d[idx]-'0'][j]);
                generate(d, v, ans, idx+1, s);
                s.pop_back();
            }
        // }
    }
    
    
    vector<string> letterCombinations(string d) {
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        int idx = 0;
        string s = "";
        if(d.size())
            generate(d, v, ans, idx, s);
        return ans;
    }
};