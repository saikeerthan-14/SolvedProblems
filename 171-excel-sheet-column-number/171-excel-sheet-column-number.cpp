class Solution {
public:
    int titleToNumber(string n) {
        int ans = 0;
        for(int i=0;i<n.size();i++) {
            ans *= 26;
            ans += n[i]-'A'+1;
        }
        return ans;
    }
};