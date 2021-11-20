class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int l = 0, h = a.size()-1;
        while(l<h) {
            int mid = (l+h)>>1;
            if(mid%2) {
                if(mid-1>=0 && a[mid]!=a[mid-1]) {
                    h = mid;
                } else {
                    l = mid+1;
                }
            } else {
                if(mid+1<a.size() && a[mid]!=a[mid+1]) {
                    h=mid;
                } else {
                    l = mid+2;
                }
            }
        }
        return a[l];
    }
};