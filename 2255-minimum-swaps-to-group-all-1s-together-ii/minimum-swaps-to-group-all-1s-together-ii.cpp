class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0, s = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==1) cnt++;
        }
        int w = nums.size()-cnt;
        int ans = cnt;
        for(int i=0;i<w;i++) {
            if(nums[i]==1) s++;
        }
        ans = min(ans, s);
        int n = nums.size(), i;
        for(int k=w;k<n+w-1;k++) {
            i = k;
            if(nums[i-w]==1) s--;
            if(k>=n) i=k%n;
            if(nums[i]==1) s++;
            ans = min(ans, s);
        }
        return ans;
    }
};