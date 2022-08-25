class Solution {
public:
    bool canConstruct(string t, string s) {
        int v[26] = {0};
        for(char c: s) {
            v[c-'a']++;
        }
        for( char c: t) {
            if(v[c-'a']==0) return false;
            v[c-'a']--;
        }
        return true;
    }
};