class Solution {
public:
    long long arrangeCoins(long long n) {
        return (sqrt(8*n+1)-1)/2;
    }
};