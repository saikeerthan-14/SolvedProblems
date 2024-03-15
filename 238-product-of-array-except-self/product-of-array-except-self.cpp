class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans (n, 0), s(n, 0);
        s[n-1] = nums[n-1];
        for(int i=n-2;i>0;i--) {
            s[i] = s[i+1]*nums[i];
            
        }
        ans[0] = s[1];
        int pref = nums[0];
        for(int i=1;i<n-1;i++) {

            ans[i] = pref*s[i+1];
            pref *= nums[i];


        }
        ans[n-1] = pref;
        return ans;
    }
};