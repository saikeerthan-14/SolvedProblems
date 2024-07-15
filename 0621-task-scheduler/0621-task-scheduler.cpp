class Solution {
public:
    int leastInterval(vector<char>& nums, int n) {
        int ans = 0;
        unordered_map<char, int> u;
        int ma = INT_MIN, cnt = 0;
        for(int i=0;i<nums.size();i++) {
            u[nums[i]]++;
            if(ma < u[nums[i]]) {
                ma = u[nums[i]];
                cnt = 0;
            }
            if(ma==u[nums[i]]) cnt++;

        }
        ans = (n+1) * (ma-1) + cnt;
        n = nums.size();
        return max(ans, n);
    }
};