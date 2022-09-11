class Solution {
public:
    
    int recur(vector<int>& prices, int i, int j, int k, vector<vector<vector<int>>>& dp){
        
        if(i == prices.size() || k == 0) return 0;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        int profit = 0;
        
        if(j) { // buy
            profit = max (
                -prices[i] + recur(prices, i+1, 0, k, dp),
                recur(prices, i+1, 1, k, dp)
            );
        } else { // sell
            profit = max (
                prices[i] + recur(prices, i+1, 1, k-1, dp),
                recur(prices, i+1, 0, k, dp)
            ); 
        }
            
        return dp[i][j][k] = profit;
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>> (2,vector<int> (k+1, -1)));
        
        int n = prices.size();
        
        // TC: O(2*n*k) SC: O(2*n*k) for memoization
        
        // base case when we reach end of array: n
        for(int i=0;i<=k;i++){
            dp[n][0][i] = 0;
            dp[n][1][i] = 0;
        }
        
        // base case when we run out of allowed transactions: k == 0
        for(int i=0;i<=n;i++){
            dp[i][0][0] = 0;
            dp[i][1][0] = 0;
        }
        
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=1; j++) {
                for( int c = 1; c<=k; c++) {
                        int profit = 0;
        
                        if(j) { // buy
                            profit = max (
                                -prices[i] + dp[i+1][0][c],
                                dp[i+1][1][c]
                            );
                        } else { // sell
                            profit = max (
                                prices[i] + dp[i+1][1][c-1],
                                dp[i+1][0][c]
                            ); 
                        }
                    
                        dp[i][j][c] = profit;
                }
            }
        }
        
        // return recur(prices,0,1,k,dp);
        return dp[0][1][k];
    }
};