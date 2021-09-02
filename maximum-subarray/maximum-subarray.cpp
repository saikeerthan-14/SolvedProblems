class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0, ma = nums[0];
        for(int i=0;i<nums.size();i++) {
            if(s<0) {
                s = nums[i];
            } else {
                s += nums[i];
            }
            ma = max(ma, s);
        }
        return ma;
    }
};