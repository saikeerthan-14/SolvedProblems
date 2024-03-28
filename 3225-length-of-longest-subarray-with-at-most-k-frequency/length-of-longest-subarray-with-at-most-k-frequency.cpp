class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 1;
        unordered_map<int, int>u;
        for(int l=0, r=0;r<nums.size();r++) {
            int k1 = nums[r];
            u[k1]++;
            while(l<r && u[k1]>k) {
                u[nums[l++]]--;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};