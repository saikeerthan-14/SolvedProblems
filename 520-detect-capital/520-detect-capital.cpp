class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        for(char c: word) {
            if(isupper(c)) cap++;
        }
        if(cap==0 || cap==word.size() || (cap==1 && isupper(word[0]))) return true;
        return false;
    }
};