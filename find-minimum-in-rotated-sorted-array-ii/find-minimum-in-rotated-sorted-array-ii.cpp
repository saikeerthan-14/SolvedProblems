class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans;
        while(l!=r){
            int mid = l +(r-l)/2;
          if(nums[mid]>nums[r])  l=mid+1;
            else if(nums[mid]<nums[r]) r=mid;
            else r--;
        }
        return nums[l];
        
    }
};