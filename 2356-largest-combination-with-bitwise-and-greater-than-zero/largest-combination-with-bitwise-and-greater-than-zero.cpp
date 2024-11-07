class Solution {
public:
    int largestCombination(vector<int>& cd) {
        int ans = 1;
        unordered_map<int, int>u;
        for(int i=0;i<=31;i++) {
            // cout<<i<<": ";
            for(int j=0;j<cd.size();j++) {
                if(cd[j]>>i&1) {
                    u[i]++;
                    ans = max(ans, u[i]);
                }
            }
            // cout<<endl;
        }
        return ans;
    }
};