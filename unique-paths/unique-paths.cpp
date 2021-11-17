class Solution {
public:
    int count(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i>=m || j>=n) return 0;
        else if(i==m-1 && j==n-1) return 1;
        else if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = count(i+1, j, m, n, dp) + count(i, j+1, m, n, dp);
        // return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // // for(int i=0;i<m;i++){
        // //     for(int j=0;j<n;j++)
        // //         cout<<dp[i][j]<< " ";
        // //     cout<<endl;
        // // }
        // // return 0;
        // return count(0,0, m, n, dp);
        long long int ans = 1, nu=1, d=1;
        for(int i=m+n-2, j=1;j<min(m,n);i--,j++) {
            nu *= i;
            d*=j;
        }
        // cout<<n
        ans = nu/d;
        return (int)ans;
    }
};