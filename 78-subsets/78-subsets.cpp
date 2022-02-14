class Solution {
public:
    void generate(vector<int>&nums, vector<vector<int>> &ans, int idx, vector<int>&v) {
        // if(idx>=nums.size()) return;
        ans.push_back(v);
        for(int i = idx;i<nums.size();i++) {
            v.push_back(nums[i]);
            generate(nums, ans, i+1, v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        generate(nums, ans, 0, v);
        return ans;
    }
};