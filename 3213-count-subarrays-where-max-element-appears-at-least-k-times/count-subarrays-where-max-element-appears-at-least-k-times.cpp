class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int ans = 0, max_e = *max_element(nums.begin(),nums.end());
        long long int freq = 0, n=nums.size();
        // for(int i=0;i<n;i++) max_e = max(max_e, nums[i]);
        long long int l =0, r = 0;
        while(r<n) {
            if(nums[r] == max_e) {
                freq++;
            }
            // cout<<l<<" "<<r<<endl;
            while(freq>=k) {
                ans += n-r;
                // l++;
                if(nums[l]==max_e) freq--;
                l++;
                // cout<<"e "<<ans<<endl;
            }

             r++;
        }
        return ans;
    }
};