class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<long long> prefix(n);
        map<int,int> m;
        int i=0,j=0;
        int maxsum=0;
        long long sum=0;
        while(j<n){
            sum+=nums[j];
            prefix[j]=sum;
            int val=nums[j];
            while(i<n and m[val]!=0){
                m[nums[i]]--;
                i++;
            }
            m[nums[j]]++;
            if(i!=0){
                if(maxsum<prefix[j]-prefix[i-1]) maxsum=prefix[j]-prefix[i-1];
            }
            else{
                if(maxsum<prefix[j]) maxsum=prefix[j];
            }
            j++;
        }
        return maxsum;
    }
};