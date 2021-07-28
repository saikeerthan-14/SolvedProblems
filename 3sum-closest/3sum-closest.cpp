class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), min_diff = INT_MAX, ans;
        for(int i=0;i<n-2;i++) {
            int p1 = i+1, p2 = n-1, k;
            while(p1<p2) {
                k = nums[p1] + nums[p2] + nums[i];
                if(k == target) {
                    return min_diff = k; 
                } else if(k > target) {
                    p2--;
                } else {
                    p1++;
                }
                if(abs(k- target)<min_diff) {
                    min_diff = abs(k-target);
                    ans = k;
                } 
            }
            
        }
        return ans;
    }
};