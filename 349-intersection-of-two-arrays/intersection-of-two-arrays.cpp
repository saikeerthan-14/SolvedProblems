class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> u1(nums1.begin(), nums1.end());
        unordered_set<int> u2(nums2.begin(), nums2.end());
        vector<int> ans;
        for(int it: u1) {
            if(u2.find(it)!=u2.end()) {
                ans.push_back(it);
            }
        }
        return ans;
    }
};