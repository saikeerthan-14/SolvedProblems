class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, n=s.size();
        bool sp_seen = false;
        for(int i=n-1;i>=0;i--) {
            if(s[i]==' '){
                if(sp_seen) return ans;
                
            }
            else {
                sp_seen = true;
                ans++;
            }
        }
        return ans;
    }
};