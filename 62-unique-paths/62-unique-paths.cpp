class Solution {
public:
    int count(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i>=m || j>=n) return 0;
        else if(i==m-1 && j==n-1) return 1;
        else if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = count(i+1, j, m, n, dp) + count(i, j+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return count(0,0, m, n, dp);
    }
};