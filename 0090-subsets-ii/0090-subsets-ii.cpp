class Solution {
public:
    void helper(vector<int>& nums, vector<int>& tmp, vector<vector<int>>&ans, int idx) {
        ans.push_back(tmp);
        for(int i=idx;i<nums.size();i++) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            tmp.push_back(nums[i]);
            helper(nums, tmp, ans, i+1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>tmp = {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(nums, tmp, ans, 0);
        return ans;

    }
};