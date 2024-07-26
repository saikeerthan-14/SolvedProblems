class Solution {
public:
    void helper(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& ans, bitset<6>& b) {
        if(tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(b[i]==false) {
                tmp.push_back(nums[i]);
                b[i] = true;
                helper(nums, tmp, ans, b);
                tmp.pop_back();
                b[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> tmp;
        bitset<6>b;
        helper(nums, tmp, ans, b);
        return ans;
    }
};