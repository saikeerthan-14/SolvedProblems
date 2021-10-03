class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n = nums.size();
        if(n==1) return true;
        int destIndex=n-1;
        
        for(int i=n-1;i>=0;i--){
           if(nums[i]>destIndex-i-1){
               destIndex = i;
            }
        }
        return destIndex==0;
    }
};