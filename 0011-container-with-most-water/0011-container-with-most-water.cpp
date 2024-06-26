class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0;
        int i=0, j=h.size()-1;
        while(i<j) {
            ans = max(ans, min(h[i], h[j])*(j-i));
            if(h[i]<h[j]) i++;
            else if(h[i]>h[j]) j--;
            else i++, j--;
        }
        return ans;
    }
};