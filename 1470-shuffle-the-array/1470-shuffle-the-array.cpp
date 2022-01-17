class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v(2*n, 0);
        int k=0;
        for(int i=0;i<n;i++) {
            v[2*k] = nums[i];
            v[2*k + 1] = nums[n+i];
            k++;
        }
        return v;
    }
};