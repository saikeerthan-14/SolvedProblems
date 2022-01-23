class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans; 
        for (int x = 1; x <= 9; ++x) {
            int val = 0; 
            for (int d = x; d <= 9; ++d) {
                val = 10*val + d; 
                if (low <= val && val <= high) ans.push_back(val); 
            }
        }
        sort(ans.begin(), ans.end()); 
        return ans; 
    }
};