class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int L) {
        auto s = to_string(L);
        int cnt = 0, N = size(s), M = size(D);
        for(int i = 1; i < N; i++) cnt += pow(M, i);
        for(int i = 0, j; i < N; i++) {
            cnt += pow(M, N-1-i) * (j = lower_bound(begin(D), end(D), s[i], [](auto d, auto v){return d[0] < v;}) - begin(D));
            if(j >= M || D[j][0] != s[i]) return cnt;
        }
        return cnt+1;
    }
};