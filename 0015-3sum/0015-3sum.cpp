class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++) {
            while(i<n && i>0 && nums[i-1]==nums[i]) i++;
            int j = i+1, k = n-1;

            while(j<k) {
                // cout<<i<<" "<<j<<" "<<k<<endl;
                // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                // cout<<"--"<<endl;
                if(nums[j] + nums[k] == -nums[i]) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<n && j<k && nums[j-1]==nums[j]) j++;
                    while(k>0 && j<k && nums[k+1]==nums[k]) k--;
                } else if(nums[j] + nums[k] < -nums[i]) {
                    j++;
                } else {
                    k--;
                }
                // break;
            }
        }
        return ans;
    }
};