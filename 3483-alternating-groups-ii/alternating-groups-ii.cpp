class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int ans = 0, f=0;
        // for(int i=0;i<k;i++) {

        //     if(i>0 && nums[i]==nums[i-1]) {
        //         f = 1;
        //         break;
        //     }
        // }
        // if(!f) ans++;
        int n = nums.size(), i=0, j=1;
        while(i<n) {
            // cout<<i<<" "<<j<<" ";
            if((j-i+1)<k) {
                if(nums[j%n]==nums[(j-1)%n]) {
                    i = j;
                }
            } else {
                if(nums[j%n]!=nums[(j-1)%n]) ans++, i++;
                else i=j;
            }
            j++;
            // cout<<ans<<endl;
        }
        return ans;
    }
};