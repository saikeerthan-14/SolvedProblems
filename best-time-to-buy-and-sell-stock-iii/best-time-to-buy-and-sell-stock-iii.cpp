class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f, s, p1, p2;
        f = s = INT_MAX;
        p1 = p2 = 0;
        for(int i: prices) {
            f = min(f, i);
            p1 = max(p1, i-f);
            s = min(s, i-p1);
            p2 = max(p2, i-s);
        }
        return p2;
    }
};