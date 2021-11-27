class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(size(nums),1);
        for(int i = 0, suf = 1, pre = 1, n = size(nums); i < n; i++) {
            ans[i] *= pre;             // similar to prefix product being calculated in 1st loop of previous solution
            pre *= nums[i];			
            ans[n-1-i] *= suf;         // similar to suffix product being calculated in 2nd loop of previous solution
            suf *= nums[n-1-i];
        }
        return ans;
    }
};