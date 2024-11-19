class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>u;
        int i=0;
        long long sum=0, ans = 0;
        while(i<k) {
            sum += nums[i];
            u[nums[i]]++;
            i++;
        }
        if(u.size()==k) ans = max(ans, sum);
        while(i<nums.size()) {
            sum -= nums[i-k];
            u[nums[i-k]]--;
            if(u[nums[i-k]]==0) u.erase(nums[i-k]);
            sum+=nums[i];
            u[nums[i]]++;
            if(u.size()==k) ans = max(ans, sum);
            i++;
        }
        return ans;
    }
};