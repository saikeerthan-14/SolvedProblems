class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stck; int n = s.length(),count=0,res=0;
        for(int i=0;i<n;i++){
            if(s[i] == '(') stck.push(i);
            else if(!stck.empty()) { s[stck.top()]= s[i] = '*'; stck.pop();}
        }
        for(int i=0;i<n;i++){
            if(s[i]== '*') count++;
            else { res = max(res,count); count=0; }
        }
        res = max(res,count); return res;
    }
};