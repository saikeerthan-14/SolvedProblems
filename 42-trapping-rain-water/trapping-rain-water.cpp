class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int lm = height[l], rm = height[r];
        int ans = 0;
        while(l<r) {
            if(height[l] < height[r]) {
                lm = max(lm, height[l]);
                ans += (lm - height[l]);
                l++;
            } else {
                rm = max(rm, height[r]);
                ans += (rm - height[r]);
                r--;
            }

        }
        return ans;
    }
};