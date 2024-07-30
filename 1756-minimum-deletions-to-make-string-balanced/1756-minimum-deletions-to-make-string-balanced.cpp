class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> suf(n, 0);
        for(int i=n-2;i>=0;i--) {
            suf[i] += suf[i+1] + (s[i+1]=='a'?1:0);
        }
        if(suf[0]==0) return 0;
        int p = 0, ans = n;
        
        for(int i=0;i<n;i++) {
            p += ((i>0 && s[i-1]=='b')?1:0);
            // cout<<i<<" "<<ans<<" "<<p+suf[i]<<" "<<p<<" "<<suf[i]<<" ";
            ans = min(ans,p+suf[i]);
            // cout<<ans<<endl;
        }
        if(p==0) return 0;
        return ans;
    }
};