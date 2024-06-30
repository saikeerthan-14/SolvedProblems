class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l = 0, h = nums.size()-1, m;
        while(l<=h) {
            m = l + (h-l)/2;
            cout<<m<<endl;
            if(nums[m]==t) return m;
            else if(nums[m]<t) l = m+1;
            else h = m-1;
        }
        return -1;
    }
};
