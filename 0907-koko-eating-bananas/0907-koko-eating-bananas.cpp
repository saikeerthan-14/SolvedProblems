class Solution {
public:
    bool valid(vector<int>& nums, int t, int m) {
        for(int i=0;i<nums.size();i++) {
            t -= nums[i]/m;
            if(nums[i]%m) t--;
            if(t<0) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& nums, int t) {
        long long l = 1, h = 0, m;
        for(int i=0;i<nums.size();i++) {
            h+=nums[i];
        }
        while(l<h) {
            m = l + (h-l)/2;
            cout<<m<<endl;
            if(valid(nums, t, m)) {
                h = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }
};