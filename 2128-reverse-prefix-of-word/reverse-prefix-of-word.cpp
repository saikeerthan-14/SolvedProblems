class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = word.find(ch);
        reverse(word.begin(), word.begin()+idx+1);
        return word;
    }
};