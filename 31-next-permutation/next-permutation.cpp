class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        // cout<<i<<endl;
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
    }
};