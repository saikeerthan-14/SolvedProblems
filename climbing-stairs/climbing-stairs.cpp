class Solution {
public:
    int climbStairs(int n) {
        if(n<=0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 2;
        int ans, s2 = 1, s1 = 2;
        for(int i=3;i<=n;i++) {
            ans = s1+s2;
            s2 = s1;
            s1 = ans;
        }
        return ans;
    }
};