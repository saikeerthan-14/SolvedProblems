class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int l=-1, h=-1;
        if(nums.size()==0) return {l, h};
        auto lb = lower_bound(nums.begin(), nums.end(), t);
        if(lb!=nums.end() && *lb == t) {
            l = lb-nums.begin();
        } else {
            return {l, h};
        }
        auto ub = upper_bound(nums.begin(), nums.end(), t) -1;
        if(*ub == t) {
            h = ub-nums.begin();
        }
        return {l, h};
        
    }
};