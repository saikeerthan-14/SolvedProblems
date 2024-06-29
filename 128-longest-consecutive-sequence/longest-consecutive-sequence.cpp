class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> u (nums.begin(), nums.end());
        int ans = 0, cnt = 0, k;
        for(int i=0;i<nums.size();i++) {
            k = nums[i];
            if(u.count(k-1)) continue;
            while(u.count(k)) {
                cnt++;
                k++;
            }
            ans = max(ans, cnt);
            cnt = 0;
        }
        return ans;

    }
};
