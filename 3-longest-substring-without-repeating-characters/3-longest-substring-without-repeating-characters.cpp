class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ma=0, p1=0, p2=0;
        vector<int>v (256, -1);
        while(p2<n) {
            if(v[s[p2]] != -1) {
                p1 = max(v[s[p2]]+1, p1);
                // p1 = v[s[p2]]+1;
            }
            v[s[p2++]] = p2;
            // p2++;
            ma = max(ma, p2-p1);
            // cout<<p2<<" "<<ma<<endl;
        }
        return ma;
    }
};