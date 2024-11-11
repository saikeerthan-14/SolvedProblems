class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;
        n--;
        for(int i=0;i<64;i++) {
            
            if(!(num&(1LL<<i))) {
                // cout<<(num>>i)<<" - ";
                num |= (n&1)*(1LL<<i);
                n = n>>1;
                // if(n==0) break;
            }
            // cout<<(num>>i)<<" "<<((num>>i)&1)<<endl;

        }
        return num;
    }
};