class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> s1;
        int cnt=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') s1.push(s[i]);
            else {
                if(!s1.empty()) s1.pop();
                else cnt++;
            }
        }
        return s1.size()+cnt;
    }
};