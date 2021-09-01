class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), i=0, j;
        j = n-1;
        while(i<j) {
            swap(s[i++], s[j--]);
        }
        i = 0;
        // cout<<s<<endl;
        string ans;
        while(i<n) {
            while(i<n && s[i]==' ') i++;
            int s1 = i;
            while(i<n && s[i]!=' ') i++;
            int e = i--;
            while(i>=s1) {
                ans.push_back(s[i--]);
            }
            // cout<<ans<<endl;
            ans.push_back(' ');
            i = e;
        }
        while(ans[ans.size()-1]==' '){
            ans.pop_back();
        }
        return ans;
    }
};