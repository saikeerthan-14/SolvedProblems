class Solution {
public:
    void combine(int idx, int t, vector<int>c, vector<int> comb, vector<vector<int>>&ans) {
        if(t==0) {
            ans.push_back(comb);
            return;
        } 
        for(int i=idx;i<c.size();i++) {
            if(c[i]<=t) {
                comb.push_back(c[i]);
                combine(i, t-c[i], c, comb, ans);
                comb.pop_back();
            }
        }

    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        sort(c.begin(), c.end(), greater<int>());
        vector<vector<int>> ans;
        combine(0, t, c, {}, ans);
        return ans;
    }
};