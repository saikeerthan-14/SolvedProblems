class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int t) {
        int n = nums.size(), m = nums[0].size();
        int l = 0, h = m*n-1, mid, r, c;
        while(l<=h) {
            mid = l + (h-l)/2;
            r = mid/m;
            c = mid%m;
            if(nums[r][c] == t) return true;
            else if(nums[r][c] < t) l = mid+1;
            else h = mid-1;
        }
        return false;
    }
};
