class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]<0) nums[i] = 0;
        }
        for(int i=0;i<n;i++) {
            // if(nums[i]!= INT_MIN) {
                int idx = abs(nums[i])-1;
                if(idx<0 || idx>=n) continue;
                if(nums[idx]>0)
                    nums[idx] *= -1;
                else if(nums[idx]==0) {
                    nums[idx] = -999;
                }
            // }
            
        }
        for(int i=0;i<n;i++) {
            if(nums[i]>=0) return i+1;
        }
        return n+1;
    }
};