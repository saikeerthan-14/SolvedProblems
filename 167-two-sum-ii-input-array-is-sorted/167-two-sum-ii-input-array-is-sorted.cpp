class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int p1=0, p2=nums.size()-1;
        while(p1<p2) {
            if(nums[p1]+nums[p2]==target) {
                return {p1+1, p2+1};
            } else if(nums[p1] + nums[p2] < target) {
                p1++;
            } else {
                p2--;
            }
        }
        return {-1, -1};
    }
};