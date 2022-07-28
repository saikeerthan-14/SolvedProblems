class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26]={0};
        for(char i:s) {
            cnt[i-'a']++;
        }
        for(char i: t) {
            cnt[i-'a']--;
        }
        for(int i=0;i<26;i++) {
            if(cnt[i]!=0) return false;
        }
        return true;
    }
};