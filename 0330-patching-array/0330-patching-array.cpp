class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0, i=0;
        long long int sum = 0;
        
        for(int i=0;i<nums.size();i++) {
            while(sum < n && sum+1 < nums[i]) {
                // cout<<sum+1<<endl;
                ans++;
                sum += (sum+1);
                
            }
            sum += nums[i];
            if(sum>=n) return ans; //1
        }
        while(sum < n) {
                // cout<<sum+1<<endl;

                ans++;
                sum += (sum+1);
            }
        return ans;
    }
};