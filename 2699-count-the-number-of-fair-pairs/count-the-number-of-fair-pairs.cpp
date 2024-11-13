class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int  i=0, j, k;
        long long ans = 0;
        for(int i=0;i<nums.size()-1;i++) {
            j = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i])-nums.begin();
            k = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i])-nums.begin();
            // cout<<i<<" "<<j<<" "<<k<<"\n";
            ans += (k-j); 
        }
        return ans;
    }
};