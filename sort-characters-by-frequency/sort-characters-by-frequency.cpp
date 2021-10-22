class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> u;
        for(char c: s) {
            u[c]++;
        }
        vector<vector<char>>v(s.size()+1);
        for(auto [c, f]: u) {
            v[f].push_back(c);
        }
        string ans = "";
        for (int i = s.size(); i > 0; i--) {
            for (auto ch : v[i]) {
                ans += string(i, ch);
            }
        }
        return ans;
    }
};