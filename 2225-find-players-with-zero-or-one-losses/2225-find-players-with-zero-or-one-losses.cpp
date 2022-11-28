class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        vector<vector<int>> ans;
        unordered_map<int, int>u1,u2;
        vector<int> v1, v2;
        for(int i=0;i<m.size();i++) {
            u1[m[i][1]] = INT_MIN;
            
            u1[m[i][0]]++;
            u2[m[i][1]]--;
            
        }
        for(auto i: u2) {
            if(i.second==-1) {
                v2.push_back(i.first);
            }
        }
        for(auto i: u1) {
            if(i.second>0) {
                v1.push_back(i.first);
            }
        }
        if(v2.size())
            sort(v2.begin(), v2.end());
        if(v1.size())
            sort(v1.begin(), v1.end());
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};