class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        vector<int> dp(n+1,INT_MAX);
        dp[n-1]=1;
        for(int j=m-1;j>=0;j--){
            for(int i=n-1;i>=0;i--){
                dp[i]=min(dp[i],dp[i+1])-dungeon[i][j];
                dp[i]=max(1,dp[i]);
            }
        }
        return dp[0];
    }
};