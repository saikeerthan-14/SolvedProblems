class Solution {
public:
    void generate(int idx, vector<int> nums, vector<int> ss, vector<vector<int>>&ans) {
        ans.push_back(ss);
        for(int i=idx;i<nums.size();i++) {
            if(i!=idx && nums[i-1] == nums[i]) continue;
            ss.push_back(nums[i]);
            generate(i+1, nums, ss, ans);
            ss.pop_back();   
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        generate(0, nums, {}, ans);
        return ans;
    }
};