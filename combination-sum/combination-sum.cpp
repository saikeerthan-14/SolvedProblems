class Solution {
public:
    void generate(int idx, vector<int>v, vector<int>&c, vector<vector<int>>&ans, int t) {
        if(t==0) {
            ans.push_back(v);
            return;
        }
        if(idx==c.size()) {
            return;
        }
        for(int i=idx; i<c.size();i++) {
            if(c[i]>t) continue;
            v.push_back(c[i]);
            generate(i, v, c, ans, t-c[i]);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<vector<int>> ans;
        generate(0, {}, c, ans, t);
        return ans;
    }
};