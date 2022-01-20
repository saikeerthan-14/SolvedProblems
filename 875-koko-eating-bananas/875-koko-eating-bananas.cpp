class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int lo = 1, hi = 1e9;
        while(lo<=hi) {
            int k = lo + (hi-lo)/2;
            int cnt = 0;
            for(int i=0;i<p.size();i++) {
                if(p[i]%k) cnt += p[i]/k + 1;
                else cnt += p[i]/k;
            }
            // cout<<lo<<" "<<k<<" "<<hi<<" "<<cnt<<endl;
            if(cnt<=h) hi = k-1;
            else lo = k+1;
        }
        return lo;
    }
};