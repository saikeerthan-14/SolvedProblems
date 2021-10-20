class Solution {
public:
    string reverseWords(string s) {
        
        string tmp = "";
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i] == ' ' && s[i+1] == ' ' || (tmp.size() == 0 && s[i] == ' '))
            {
                continue;
            }
            tmp += s[i];
        }
        if(s.back() != ' ')tmp+=s.back();
        s = tmp;
        reverse(s.begin(), s.end());
        
        int p1 = 0,p2=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                reverse(s.begin() + p1, s.begin() + p2);
                p1 = i+1;
                p2 = i+1;
            }
            else
            {
                p2++;
            }
        }
        reverse(s.begin() + p1, s.begin() + p2);
        return s;
    }
};