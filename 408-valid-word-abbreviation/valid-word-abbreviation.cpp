class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int idx = 0;
        string num="";
        for (int i=0;i<abbr.size();i++) {
            if(isdigit(abbr[i])) {
                if(num == "" && abbr[i]=='0') return false;
                num.push_back(abbr[i]);
            } else {
                if(num!="") {
                    int val = stoi(num);
                    if(idx+val < word.size()) idx+=val;
                    else return false;
                    num = "";
                }
                if(abbr[i]!=word[idx]) return false;
                idx++;
                
            }
        }
        if(num!="") {
            int val = stoi(num);
            idx+= val;
        }
                
        return idx==word.size();
    }
};