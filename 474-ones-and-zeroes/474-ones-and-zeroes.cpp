class Solution {
public:
    int dp[101][101][601]; // m,n,idx
    int helper(vector<string>& strs, int m, int n, int idx)
    {
        /* Helper takes, strs arr, m (max 0s), n (max 1s) and idx (current string).
        *  For each strs[idx] we either consider it or not.
        *  When we consider the str[idx] string, we'll also update m and n.
        *  At the end, we'll return max(considered, not_considered).
        */
        
        if (idx >= strs.size()) { // Reached end of strs arr.
            return 0;
        }
        // If result is already calculated
        // then return it, no need to go further.
        if (dp[m][n][idx] != -1) 
            return dp[m][n][idx];

        // res1 holds the max number of elems if strs[idx]
        // is NOT considered for final set.
        int res1 = helper(strs, m, n, idx+1);
        
        // res2 holds the max number of elems if strs[idx]
        // is considered for final set.
        // (Don't forget to update m and n.)
        int count[2] = {0,0};
        for (int i = 0; i < strs[idx].length(); i++){
            if (strs[idx][i] == '0') count[0]++;
            else count[1]++;
        }
        int res2 = 0;
        if (!(m - count[0] < 0 || n - count[1] < 0)){
            res2 = 1 + helper(strs, m - count[0] , n - count[1], idx+1);
        }
        
        // Store result for current m, n and idx in dp
        // and return it.
        dp[m][n][idx] = max(res2, res1);
        return dp[m][n][idx];
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return helper(strs, m, n, 0);
    }
};
