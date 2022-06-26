class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int ts=0;
        for(auto i:cp)
        {
            ts+=i;
        }
        int n=cp.size();
        int len=n-k;
        int i=0,sum=0,minsum=ts;
         if(n==k) return ts;
        for(int j=0;j<n;j++)
        {
            sum+=cp[j];
            if(len==j-i+1)
            {
                minsum=min(minsum,sum);
                sum-=cp[i++];
            }
        }
        return ts-minsum;
    }
};