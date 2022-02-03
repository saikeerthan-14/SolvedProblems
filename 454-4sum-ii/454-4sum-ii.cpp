class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int>u1, u2;
        int ans=0;
        for(int i:nums1) {
            for(int j:nums2) {
                u1[i+j]++;
            }
        }
        
        for(int i:nums3) {
            for(int j:nums4) {
                u2[i+j]++;
            }
        }
        
        for(auto i: u1) {
            if(u2.find(-1*i.first)!=u2.end()) {
                ans += i.second * u2[-1*i.first];
            }
        }
        return ans;
        
    }
};