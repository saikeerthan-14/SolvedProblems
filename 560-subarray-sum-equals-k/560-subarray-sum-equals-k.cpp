class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> u;
        int sum = 0, cnt = 0;
        u[0] = 1;
        for(int i: nums) {
            sum += i;
            if(u.find(sum-k)!=u.end()) {
                cnt += u[sum-k];
            }
            u[sum]++;
        }
        return cnt;
    }
};