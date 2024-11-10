class Solution {
public:
    void update(vector<int>&v, int n, int p) {
        for(int i=0;i<32;i++) {
            if((n>>i)&1) {
                v[i] += p;
            }
        }
    }

    int count(vector<int>&v) {
        int res = 0;
        for(int i=0;i<32;i++) {
            if(v[i]!=0) {
                res |= 1<<i;
            }
        }
        return res;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i=0, j=0;
        int mi = nums.size()+1;
        vector<int> v(32, 0);
        while(j<nums.size()) {

            // cout<<ans<<" "<<i<<" "<<j<< "---";
            // ans |= nums[j];
            update(v, nums[j], 1);

            while(i<=j && count(v)>=k) {
                mi = min(j-i+1, mi);
                // ans = ans & ~nums[i];
                update(v, nums[i], -1);
                i++;
            } 
            j++;
            // cout<<ans<<" "<<i<<" "<<j<<endl;

        }
        if(mi>=nums.size()+1) return -1;
        return mi;
    }
};