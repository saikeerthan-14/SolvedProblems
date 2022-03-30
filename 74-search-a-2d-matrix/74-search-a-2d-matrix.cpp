class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r = m.size(), c = m[0].size();
        int l=0, h = r*c-1, mi;
        while(l<=h) {
            mi = l + (h-l)/2;
            int z = m[mi/c][mi%c];
            if(t==z) return true;
            else if(t>z) {
                l = mi+1;
            } else {
                h = mi-1;
            }
        }
        return false;
    }
};