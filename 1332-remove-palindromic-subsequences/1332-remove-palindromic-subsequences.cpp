class Solution {
public:
    int removePalindromeSub(string s) {
        string a = s;
        reverse(s.begin(),s.end());
        string b = s;
        if(a==b)
            return 1;
        int c0=0,c1=0;
        for(auto x : s)
        {
            if(x=='a')
                c0=1;
            else
                c1=1;
        }
        if(c0==0 && c1==1)
            return 1;
        else if(c0==1 && c1==0)
            return 1;
        else if(c0==1 && c1==1)
            return 2;
        return 0;
    }
};