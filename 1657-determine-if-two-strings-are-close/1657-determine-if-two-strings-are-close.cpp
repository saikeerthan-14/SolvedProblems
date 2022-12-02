class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size()!=w2.size()) return false;
        vector<int>v1(26, 0), v2(26, 0);
        for(char c: w1) {
            v1[c-'a']++;
        }
        for(char c: w2) {
            v2[c-'a']++;
        }
        for(int i=0;i<26;i++) {
            if((v1[i]>0 && v2[i]==0) || (v1[i]==0 && v2[i]>0)) {
                return false;
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1==v2;
    }
};