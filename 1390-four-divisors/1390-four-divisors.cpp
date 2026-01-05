class Solution {
public:

    long long check(int n) {
        int cnt = 0;
        long long sum = 1+n;
        int k = sqrt(n);
        if(k*k == n) return 0;
        for(int i=2;i<k+1;i++) {
            if(n%i==0) {
                cnt++;
                sum += i + (n/i);
            }
            if(cnt>1) return 0;
            // cout<<sum<<" - ";
            
            // cout<<sum<<"\n";

        }
        if(cnt==1)
            return sum;
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++) {
            // cout<<ans<<" - ";
            ans += check(nums[i]);
            // cout<<"\n===\n"<<ans<<"\n";
        }
        return ans;
    }
};