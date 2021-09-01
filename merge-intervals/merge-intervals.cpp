class Solution {
public:
    static bool comp (vector<int> &a, vector<int> &b) {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& s) {
        vector<vector<int>> ans;
        sort(s.begin(), s.end(), comp);
        int n = 0;
        ans.push_back(s[0]);
        // vector<int> v = s[0];
        for(int i=1;i<s.size();i++) {
            // v = s[i];
            if(ans[n][1]>=s[i][0]) {
                ans[n][1] = max(ans[n][1], s[i][1]);
            } else {
                ans.push_back(s[i]);
                n++;
            }
        }
        
        return ans;
    }
};