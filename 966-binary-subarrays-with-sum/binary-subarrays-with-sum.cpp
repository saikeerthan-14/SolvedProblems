class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int>u;
        int s = 0, ans = 0;
        u[0] = 1;
        for(int i=0;i<nums.size();i++) {
            s += nums[i];
            if(u.find(s-goal)!=u.end()) {
                ans += u[s-goal];
            }
            u[s]++;
            
        }
        return ans;
    }
};