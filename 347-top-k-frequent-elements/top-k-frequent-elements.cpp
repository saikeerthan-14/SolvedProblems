#define pi pair<int, int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>u;
        int n = nums.size();
        vector<vector<int>> v(n+1);
        for(int i=0;i<nums.size();i++) {
            u[nums[i]]++;
        }
        for(auto it: u) {
            v[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=n;i>=0;i--) {
            // cout<<"fds"<<endl;
            for(int j=0;j<v[i].size();j++) {
                // cout<<"fdws"<<endl;
                ans.push_back(v[i][j]);

                if(ans.size()==k) return ans;
            }
        }
        return {};
    }
};