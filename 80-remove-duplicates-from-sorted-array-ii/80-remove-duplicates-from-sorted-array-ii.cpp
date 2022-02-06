class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int md = 1e5, cnt=0, cur=INT_MIN;
        for(int i=1;i<n;i++) {
            if(nums[i-1]==nums[i]) {
                if(cur==nums[i]) nums[i] = md;
                else cur = nums[i];
                continue;
            } else if(cur==nums[i]){
                nums[i] = md;
            }
        }
        
        int p1 = 0, p2 = 1;
        
        while(p1<n && p2<n) {
            if(nums[p1] == md) {
                
                while(p2<n && nums[p1]==nums[p2]) p2++;
                if(p2<n)
                    swap(nums[p1], nums[p2]);
                // p2++;
            }
            // cout<<nums[p1]<<" ";
            p1++;
            p2++;
        }
        p1 = 0;
        int k=0;
        while(p1<n && nums[p1++]!=md) k++;
        return k;
    }
};