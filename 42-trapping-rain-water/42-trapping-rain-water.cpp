class Solution {
public:
    int trap(vector<int>& h) {
        int ans = 0, n=h.size(), l=h[0];
        vector<int> r(n,0);
        r[n-1] = h[n-1];
        for(int i=n-2;i>=0;i--) {
            r[i] = max(r[i+1], h[i]);
        }
        for(int i=0;i<n;i++) {
            l = max(l, h[i]);
            
            ans += min(l,r[i])-h[i];
        }
        return ans;
    }
};