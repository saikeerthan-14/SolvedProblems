class Solution {
public:
    int maxDepth(string s) {
        int ans =0, c=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') ans++;
            else if(s[i]==')') ans--;
            c = max(ans, c);
        }
        return c;
    }
};