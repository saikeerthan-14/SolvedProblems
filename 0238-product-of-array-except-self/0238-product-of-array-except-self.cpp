class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int prod = 1;
        for(int i=0;i<nums.size();i++) {
            ans[i] = prod;
            prod *= nums[i];
            // cout<<i<<" "<<ans[i]<<" "<<prod<<endl;
        }
        prod = 1;
        for(int i=nums.size()-1;i>=0;i--) {
            ans[i] *= prod;
            prod *= nums[i];
        }
        return ans;
    }
};
