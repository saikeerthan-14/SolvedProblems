class Solution {
public:
    string decodeString(string s) {
        string tmp, suffix;
        vector<string> ans;
        int ans_idx, num_repetitions;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ']') {
                tmp = "";
                while (ans.back()[0] != '[') {
                    tmp = ans.back() + tmp;
                    ans.pop_back();
                }
                ans.pop_back();  // skips '['
                num_repetitions = stoi(ans.back());
                ans.pop_back(); // removes num_repetitions
                suffix = "";
                while (num_repetitions > 0) {
                    suffix += tmp;
                    --num_repetitions;
                }
                ans.push_back(suffix);
            } else if (s[i] >= '0' && s[i] <= '9') {
                tmp = s[i];
                while (s[i+1] >= '0' && s[i+1] <= '9') {
                    ++i;
                    tmp += s[i];
                }
                ans.push_back(tmp);  // number of repetitions [1, 300]
            } else if (s[i] == '[') {
                tmp = string(1, s[i]);
                ans.push_back(tmp);
            } else {
                tmp = s[i];
                while (s[i+1] >= 'a' && s[i+1] <= 'z') {
                    ++i;
                    tmp += s[i];
                }
                ans.push_back(tmp);
            }
        }
        tmp = "";
        for (const auto& str : ans) {
            tmp += str;
        }
        return tmp;
    }
};