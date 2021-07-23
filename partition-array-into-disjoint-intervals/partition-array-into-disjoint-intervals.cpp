static auto _ = []
    {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        return 0;
    }();
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        v[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--) {
            v[i] = min(v[i+1], nums[i]);
        }
        int p1 = nums[0];
        for(int i=1;i<n;i++) {
            // cout<<p1<<" "<<v[i]<<endl;
            if(p1<=v[i]) return i;
            p1 = max(p1, nums[i]);
        }
        return 1;
    }
};