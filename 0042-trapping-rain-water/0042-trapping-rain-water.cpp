class Solution {
public:
    int trap(vector<int>& nums) {
        int li = 0, lm = 0, ri = nums.size()-1, rm = 0;
        lm = nums[li];
        rm = nums[ri];
        int ans = 0;
        while(li<ri) {
            if(lm<rm) {
                if(lm > nums[li]) {
                    ans += lm-nums[li];
                }
                li++;
                lm = max(lm, nums[li]);
            } else {
                if(rm > nums[ri]) {
                    ans += rm-nums[ri];
                }
                ri--;
                rm = max(rm, nums[ri]);
            }
        }
        return ans;
    }
};
