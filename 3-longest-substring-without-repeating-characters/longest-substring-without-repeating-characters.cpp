class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> u;
        // vector<int> v(256, -1);
        int ans = 0, st=-1;
        for(int i=0;i<s.size();i++) {
            if(u.find(s[i])!=u.end()) {
                st = max(u[s[i]], st);
            }
            ans = max(ans, i-st);
            u[s[i]] = i;

        }
        // while(j<n) {
        //     if(v[s[j]]==-1) {
        //         v[s[j]] = j;
        //         j++;
        //     }
        // }
        return ans;
    }
};