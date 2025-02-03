class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, st = 0, i = 0;
        int n = nums.size();
        for(i=0;i<n-1;i++) {
            if(nums[i]>=nums[i+1]) {
                ans = max(ans, i-st+1);
                st = i+1;
            }
        }
        ans = max(ans, i-st+1);
        i = 0, st = 0;
        for(i=0;i<n-1;i++) {
            if(nums[i]<=nums[i+1]) {
                ans = max(ans, i-st+1);
                st = i+1;
            }
        }
        ans = max(ans, i-st+1);
        return ans;
    }
};