class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++) {
            int l = i+1, h = nums.size()-1;
            int s = -1*nums[i];
            while(l<h) {
                if(nums[l] + nums[h] == s) {
                    ans.push_back({nums[i], nums[l++], nums[h--]});
                    while(l<h && nums[l-1]==nums[l])l++;
                    while(l<h && nums[h] == nums[h+1]) h--;
                } else if(nums[l] + nums[h] < s) {
                    l++;
                } else {
                    h--;
                }
            }
            while(i<nums.size()-2 && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};