class Solution {
public:
    int maxArea(vector<int>& h) {
        int p1 = 0, p2 = h.size()-1;
        int ans = min(h[p1], h[p2])*(p2-p1);
        while(p1<p2) {
            ans = max(ans, min(h[p1], h[p2])*(p2-p1));
            if(h[p1]<h[p2]) {
                p1++;
            } else {
                p2--;
            }
        }
        return ans;
    }
};