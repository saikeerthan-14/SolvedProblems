class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(n,0),temp(5,1);
        dp[0]=5;
        for(int i=1;i<n;i++) {
            for(int j=0;j<5;j++) {
                int val=0;
                for(int k=j;k<5;k++) {
                    val+=temp[k];
                }
                temp[j]=val;
                dp[i]+=val;
            }
        }
        return dp.back();
    }
};