class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3) return s;
        int i = 2, j = 2;
        for(int i=2;i<s.size();i++) {
            if(s[i]!=s[j-1] || s[i]!=s[j-2]) {
                s[j] = s[i];
                j++;
            }
        }
        s.resize(j);
        return s;
    }
};