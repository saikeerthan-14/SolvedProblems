class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>> &ans, vector<int>& tmp, int idx) {
        ans.push_back(tmp);
        for(int i=idx; i<nums.size();i++) {
            tmp.push_back(nums[i]);
            helper(nums, ans, tmp, i+1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = nums.size();
        helper(nums, ans, tmp, 0);
        return ans;
    }
};