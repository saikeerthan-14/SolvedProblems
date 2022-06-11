class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
        }
        int t_sum = sum-x;
        if(t_sum==0) {
            return nums.size();
        } else if (t_sum<0) {
            return -1;
        }
        int ans = 0;
        int s=0, e=0, c_sum=nums[0];
        while(e<nums.size()) {
            // cout<<s<<" "<<e<<" "<<c_sum<<" "<<t_sum<<" "<<ans<<endl;
            if(c_sum<t_sum) {
                e++;
                if(e==nums.size()) break;
                c_sum+=nums[e];
            } else if(c_sum>t_sum) {
                c_sum-= nums[s];
                s++;
            } else if(c_sum==t_sum) {
                ans = max(ans, e-s+1);
                // c_sum-=nums[s];
                // s++;
                e++;
                if(e==nums.size()) break;
                c_sum+=nums[e];
            }
        }
        if(ans==0) return -1;
        return nums.size()-ans;
    }
};

// 11 , x=5
// ans = 2
// min of nums elements to be picked to get sum 5
// max of nums elements to be picked to get sum 11-5