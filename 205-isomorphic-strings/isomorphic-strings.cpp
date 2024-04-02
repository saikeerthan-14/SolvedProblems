class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s1(128, -1);
        vector<int> t1(128, -1);
        for(int i=0;i<s.size();i++) {
            if(s1[s[i]]!=t1[t[i]]) return false;
            s1[s[i]] = i;
            t1[t[i]] = i;
        }
        return true;
    }
};