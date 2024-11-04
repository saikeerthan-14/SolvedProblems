class Solution {
public:
    string compressedString(string word) {
        string s;
        // int cnt = 1;

        for(int i=0;i<word.size();) {
            int cnt = 0;
            char p = word[i];
            while(word[i]==p && cnt<9) {
                cnt++;
                i++;
            }
            s.push_back(cnt+'0');
            s.push_back(p);
        }
        return s;
    }
};