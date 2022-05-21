class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        const int BIGNUM = 1000;
        vector<int> dp(amount+1, BIGNUM);
        
        dp[0] = 0;
        
        for(int coin:coins)
            for(int j=0; j <= amount - coin; j++)
                if(dp[j] < BIGNUM)
                    dp[j+coin] = min(dp[j+coin], dp[j] + 1);
        
        return (dp[amount] < BIGNUM ? dp[amount] : -1);
    }
};
