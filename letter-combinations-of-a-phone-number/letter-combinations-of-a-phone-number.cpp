class Solution {
public:
    vector<string> map = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    }, ans;
    
    void generate(string &digits, int id, string &cmp) {
        if(id==digits.size()) {
            ans.push_back(cmp);
            return;
        }
        string tmp = map[digits[id]-'2'];
        for(int i=0;i<tmp.size();i++) {
            cmp.push_back(tmp[i]);
            generate(digits, id+1, cmp);
            cmp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits=="") return ans;
        string cmp;
        generate(digits, 0, cmp);
        return ans;
    }
};