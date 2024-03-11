class Solution {
public:
    string customSortString(string order, string s) {
        string ans;
        unordered_map<int, int> us;
        for(char c: s) {
            us[c-'a']++;
        }
        for(char c: order) {
            if(us.find(c-'a')!=us.end()) {
                for(int j=0;j<us[c-'a'];j++) {
                    ans.push_back(c);
                }
                us.erase(c-'a');
            }
        }
        for(auto i: us) {
            for(int j=0;j<i.second;j++) {
                ans.push_back(i.first+'a');
            }
        }
        return ans;
    }
};