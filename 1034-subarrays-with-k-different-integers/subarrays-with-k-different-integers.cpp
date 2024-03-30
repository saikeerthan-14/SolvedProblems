class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int cnt = 0, l=0, r =0, n = nums.size();
        unordered_map<int, int> u;
        while(r<n) {
            u[nums[r++]]++;
            while(l<=r && u.size()>k) {
                u[nums[l]]--;
                if(u[nums[l]]==0) u.erase(nums[l]);
                l++;
            }
            cnt += r-l;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};