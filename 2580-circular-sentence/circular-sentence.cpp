class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string word;
        ss>>word;
        char f = word[0], ff = word[word.size()-1], n;
        while(ss>>word) {
            n = word[0];
            if(ff!=n) return false;
            ff = word[word.size()-1];
        }

        return f==ff;
    }
};