class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ans;
        for(int i=0;i<nums.size();i++) {
            if(cnt==0) {
                ans = nums[i];
                cnt++;
            } else {
                if(ans == nums[i]) cnt++;
                else cnt--;
            }
        }
        cnt = 0;
        for(int i=0;i<nums.size();i++) if(ans==nums[i]) cnt++;
        if(cnt> nums.size()/2)
        return ans;
        return -1;
    }
};