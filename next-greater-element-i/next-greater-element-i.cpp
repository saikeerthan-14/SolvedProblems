class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        // vector<int> temp(n2, -1);
        unordered_map<int, int>u;
        u[nums2[n2-1]] = n2-1;
        // return {};
        for(int i=n2-2;i>=0;i--){
            u[nums2[i]] = i; 
        }
        vector<int> ans;
        for(int i=0;i<n1;i++) {
            int mi = INT_MAX;
            for(int j=u[nums1[i]]+1;j<n2;j++) {
                if(nums2[j]>nums1[i]) {
                    mi = nums2[j];
                    break;
                }
            }
            if(mi==INT_MAX) mi= -1;
            ans.push_back(mi);
        }
        return ans;
    }
};