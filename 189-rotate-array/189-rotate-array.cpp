class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int p1=0, p2=n-1;
        while(p1<p2) {
            swap(nums[p1++], nums[p2--]);
        }
        p1=0;
        p2=k-1;
        while(p1<p2) swap(nums[p1++], nums[p2--]);
        p1=k;p2=n-1;
                while(p1<p2) swap(nums[p1++], nums[p2--]);

    }
};