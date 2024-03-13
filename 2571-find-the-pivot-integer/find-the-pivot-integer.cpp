class Solution {
public:
    int pivotInteger(int n) {
        int ans = 0, l = 1, h = n;
        while(l<=h) {
            int m = (l+h)/2;
            int ls = (m*(m+1))/2;
            int rs = (n*(n+1))/2 - ls + m;
            // cout<<ls<<" "<<rs<<" "<<m<<"\n";
            if(ls==rs) return m;
            if(ls<rs) {
                l = m+1;
            } else {
                h = m-1;
            }
        }
        return -1;
    }
};