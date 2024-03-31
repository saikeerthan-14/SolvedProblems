class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        cout<<i<<endl;
        if(i<0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        else {
            // cout<<"enter"<<endl;
            for(int j=n-1;j>i;j--) {
                if(nums[j]>nums[i]) {
                    swap(nums[j], nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+i+1, nums.end());
        }
        // int idx = -1;
        // for(int i = n-2;i>=0;i--) {
        //     if(nums[i]<nums[i+1]) {
        //         idx = i;
        //         break;
        //     }
        // }
        // cout<<idx<<endl;
        // if(idx==-1) {
        //     reverse(nums.begin(), nums.end());
        //     return;
        // }
        // for(int i = n-1;i>idx;i--) {
        //     if(nums[i]>nums[idx])  {
        //         swap(nums[i], nums[idx]);
        //         break;
        //     }
        // }
        // reverse(nums.begin()+idx+1, nums.end());
        // return nums;
    }
};