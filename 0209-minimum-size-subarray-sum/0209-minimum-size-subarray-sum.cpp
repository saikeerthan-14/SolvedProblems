class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int i=0, j=0, s=0;
        int ans = INT_MAX;
        while(j<nums.size()+1) {
            cout<<i<<" "<<j<<" "<<s<<" "<<endl;

            if(s>=t){
                // cout<<i<<" "<<j<<endl;
                ans = min(ans, j-i);
                s -= nums[i];
                i++;
                // cout<<ans<<endl;
            } 
            else {
                if(j<nums.size())

                s += nums[j]; 

                j++;
                // if(j<nums.size())

            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};