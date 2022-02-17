class Solution {
public:
    
    void generate(vector<int>&c, vector<int>&v, vector<vector<int>>&ans, int idx, int t) {
        if(t==0) {
            ans.push_back(v);
            return;
        } 
        for(int i=idx;i<c.size();i++) {
            if(c[i]<=t) {
                v.push_back(c[i]);
                generate(c, v, ans, i, t-c[i]);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<vector<int>> ans;
        vector<int> v;
        generate(c, v, ans, 0, t);
        return ans;
    }
};