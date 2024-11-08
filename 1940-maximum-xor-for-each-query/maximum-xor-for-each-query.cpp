class Solution {
public:
    int makeMax(int s, int mb) {
        int ans = 0;
        // cout<<s<<" ";
        for(int i = 0;i<mb;i++) {
            if((s&1<<i) == 0) {
                ans |= 1<<i;
            } 
            // cout<<ans<<" ";

        }
        // cout<<"\n";
        return ans;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int ans = 0;
        for(int i=1;i<nums.size();i++) {
            nums[i] ^= nums[i-1];
        }
        for(int i=0;i<nums.size();i++) {
            nums[i] = makeMax(nums[i], maximumBit);

        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
};