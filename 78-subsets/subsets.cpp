class Solution {
public:

    void helper(int i, vector<int>&nums, vector<int>&v, vector<vector<int>>& ans) {
        if(i>=nums.size()) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        helper(i+1, nums, v, ans);
        v.pop_back();
        helper(i+1, nums, v, ans);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(0, nums, v, ans);
        return ans;
    }
};