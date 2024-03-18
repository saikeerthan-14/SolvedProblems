class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& nums2) {
        int n = nums.size(), i=0;
        vector<vector<int>> ans;
        while(i<n && nums[i][1]<nums2[0]) {
            ans.push_back(nums[i++]);
        }
        while(i<n && nums[i][0]<=nums2[1]) {
            nums2[0] = min(nums[i][0], nums2[0]);
            nums2[1] = max(nums[i][1], nums2[1]);
            i++;
        }
        ans.push_back(nums2);
        while(i<n) ans.push_back(nums[i++]);
        return ans;
    }
};