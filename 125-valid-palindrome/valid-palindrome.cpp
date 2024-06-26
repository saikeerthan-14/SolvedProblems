class Solution {
public:
    bool check(char i) {
        return isalnum(i);
    }
    bool isPalindrome(string s) {
        int i=0, j= s.size()-1;
        while(i<=j) {
            if(!check(s[i])) {
                i++;
                continue;
            }
            if(!check(s[j])) {
                j--;
                continue;
            }
            if(tolower(s[i])!=tolower(s[j])) return false;
                i++;
                j--;
        }
        return true;
    }
};