class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0, st = 0, j, k;
        for(int i=0;i<s.size();i++) {
            // odd len
            j = i-1;
            k = i+1;
            while(j>=0 && k<s.size() && s[j]==s[k]) j--, k++;
            if(max_len < k-j-1) {
                max_len = k-j-1;
                st = j+1;
            }
            // cout<<max_len<< " - ";
            
            // even len
            // if(i+1<s.size() && s[i]==s[i+1]) {
                j = i;
                k = i+1;
                while(j>=0 && k<s.size() && s[j]==s[k]) j--, k++;
                if(max_len < k-j-1) {
                    max_len = k-j-1;
                    st = j+1;
                }
            // }
            // cout<<max_len<<endl;

        }
        return s.substr(st, max_len);
    }
};