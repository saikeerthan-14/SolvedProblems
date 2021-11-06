class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans ^= nums[i];
        }
        int i, a=0, b=0;
        for(i=0;i<n;i++) {
            if(ans&(1<<i)) break;
        }
        // cout<<ans<<" "<<i<<endl;
        for(int j=0;j<n;j++) {
            if(nums[j]&(1<<i)) {
                a^=nums[j];
                // cout<<nums[i]<<endl;
            } else {
                b ^= nums[j];
            }
        }
        return {a, b};
    }
};