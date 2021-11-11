class Solution {
public:
    int minStartValue(vector<int>& A) {
        partial_sum(begin(A), end(A), begin(A));
        return -min(0, *min_element(begin(A), end(A))) + 1;
    }
};