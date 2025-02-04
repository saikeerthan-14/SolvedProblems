class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int s = nums[0], ans = 0;
        int n = nums.size();

        for(int i=0;i<n-1;i++) {
            if(nums[i]<nums[i+1]) {
                s += nums[i+1];
            } else {
                ans = max(ans, s);
                s = nums[i+1];
            }
            // cout<<i<<" "<<s<<" "<<ans<<endl;
        }
        // if(s!nu)
        ans = max(ans, s);
        return ans;
    }
};