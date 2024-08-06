class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int>v(26, 0);
        for(int i=0;i<word.size();i++) {
            v[word[i]-'a']++;
        }
        sort(v.begin(), v.end(), greater<int>());
        int cMax = v[0], j=1, steps=1;
        for(int i=0;i<26;i++) {
            if(v[i]==0) break;
            ans += (i/8 + 1)*v[i];
        }
        return ans;
    }
};