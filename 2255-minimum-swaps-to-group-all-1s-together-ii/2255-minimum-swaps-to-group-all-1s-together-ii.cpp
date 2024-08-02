class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;
        
        // Count total number of 1's and create a doubled array
        vector<int> doubledNums(2 * n);
        for (int i = 0; i < n; i++) {
            totalOnes += nums[i];
            doubledNums[i] = doubledNums[i + n] = nums[i];
        }
        
        // Edge cases
        if (totalOnes == 0 || totalOnes == n) return 0;
        
        // Create cumulative sum array
        vector<int> cumulativeSum(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            cumulativeSum[i + 1] = cumulativeSum[i] + doubledNums[i];
        }
        
        int maxOnesInWindow = 0;
        
        // Check all possible windows of size totalOnes
        for (int i = 0; i <= n; i++) {
            int onesInWindow = cumulativeSum[i + totalOnes] - cumulativeSum[i];
            maxOnesInWindow = max(maxOnesInWindow, onesInWindow);
        }
        
        return totalOnes - maxOnesInWindow;
    }
};