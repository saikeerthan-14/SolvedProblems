class Solution {
public:

    void helper(int i, vector<int>&nums, vector<int>&v, vector<vector<int>>& ans) {
        ans.push_back(v);

        if(i>=nums.size()) {
            return;
        }
        for(int j = i; j<nums.size();j++) {
            v.push_back(nums[j]);
            helper(j+1, nums, v, ans);
            v.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(0, nums, v, ans);
        return ans;
    }
};