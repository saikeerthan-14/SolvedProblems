class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, cnt=0;
        unordered_map<int, int>u;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==1) cnt++;
            else cnt--;
            
            if(cnt==0) ans = i+1;
            if(u.find(cnt) != u.end()) {
                ans = max(ans, i-u[cnt]);
            } else {
                u[cnt] = i;
            }
        }
        return ans;
    }
};