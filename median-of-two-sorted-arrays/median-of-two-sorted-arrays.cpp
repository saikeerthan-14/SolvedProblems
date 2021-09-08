class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size()) return findMedianSortedArrays(b, a);
        int n1 = a.size(), n2 = b.size();
        int l = 0, h = n1;
        while(l<=h) {
            int cut1 = l+ ((h-l)>>1);
            int cut2 = (n1+n2+1)/2 - cut1;
            int l1 = (cut1==0)?INT_MIN:a[cut1-1];
            int l2 = (cut2==0)?INT_MIN:b[cut2-1];
            int r1 = (cut1==n1)?INT_MAX:a[cut1];
            int r2 = (cut2==n2)?INT_MAX:b[cut2];
            if(l1>r2) {
                h = cut1-1;
            } else if(l2>r1) {
                l = cut1+1;
            } else if(l1<=r2 && l2<=r1) {
                if((n1+n2)%2) {
                    return max(l1, l2);
                } else {
                    return (max(l1,l2) + min(r1, r2))/2.0;
                }
            }
        }
        return 0.0;
    }
};