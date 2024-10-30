class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>v(26, 0);
        int i=0, maxf=0;
        for(int j=0;j<s.size();j++) {
            maxf = max(maxf, ++v[s[j]-'A']);
            if((j-i+1)-maxf > k) {
                v[s[i]-'A']--;
                i++;
            }
        }
        return s.length()-i;
    }
};