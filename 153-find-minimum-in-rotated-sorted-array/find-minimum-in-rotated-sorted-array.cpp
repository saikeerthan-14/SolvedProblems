class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, h = nums.size()-1, m;
        while(l<h) {
            cout<<l<<' '<<h<<endl;
            m = l + (h-l)/2;
            if(nums[m]>=nums[0]) {
                l = m+1;
            } else {
                h = m;
            }
        }
        if(nums[l]>nums[0]) return nums[0];
        return nums[l];
    }
};
