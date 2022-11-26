class Solution {
public:    
    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7;

        vector<int> idx(arr.size());
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&arr](int lhs, int rhs) { return arr[lhs] < arr[rhs]; });
        set<int> s = {-1, (int)arr.size()};
        int sum = 0;
        for (int i : idx) {
            auto lit = s.lower_bound(i);
            auto rit = lit--;
            sum = (sum + 1ll * arr[i] * (*rit - i) * (i - *lit)) % mod;            
            s.insert(i);
        }
        return sum;
    }
};