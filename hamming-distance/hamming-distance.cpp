class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while(x>0 || y>0) {
            if((x&1)!=(y&1)) {
                ans++;
                // cout<<x<<" "<<y<<endl;
            }
            if(x)
            x>>=1;
            if(y)
            y>>=1;
        }
        return ans;
    }
    Solution() {
        ios_base::sync_with_stdio(true);
        cin.tie(NULL);
        cout.tie(NULL);
    }
};