class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;
        n--;
        while(n--) {
            num = (num+1) | x;
        }
        return num;
    }
};