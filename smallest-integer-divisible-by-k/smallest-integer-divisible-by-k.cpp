class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int ans = -1, r=0;
        if(k%2==0) return ans;
        for(int N=1;N<=k;N++) {
            r = (r*10 + 1)%k;
            if(r==0) return N;
        }
        return ans;
    }
};