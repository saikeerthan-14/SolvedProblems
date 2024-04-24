class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<3) return 1;
        int a = 0;
        int b = 1;
        int c = 1;
        int d, i=3;
        while(i<=n) {
            d = a+b+c;
            a = b;
            b = c;
            c = d;
            i++;
        }
        return d;
    }
};