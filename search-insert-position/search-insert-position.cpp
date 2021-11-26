class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int l = 0, h = nums.size()-1, ans;
        if(t>nums[h]) return h+1;
        else if (t<nums[0]) return 0;
        while(l<=h) {
            int m = l + (h-l)/2;
            if(nums[m]==t) return m;
            else if(nums[m]<t) {
                l = m+1;
                ans = m+1;
            } else {
                ans = m;
                h = m-1;
            }
            
        }
        return ans;
    }
};