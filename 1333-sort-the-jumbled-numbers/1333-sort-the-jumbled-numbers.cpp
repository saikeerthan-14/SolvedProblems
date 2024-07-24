class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;
        priority_queue<pair<int, int>>pq;
        for(int i=0;i<nums.size();i++) {
            string p = to_string(nums[i]);
            int k = 0;
            for(int j=0;j<p.size();j++) {
                k = k*10 + mapping[p[j]-'0'];
            }
            // cout<<k<<" "<<nums[i]<<endl;
            pq.push({-k, -i});
        }
        while(!pq.empty()) {
            pair<int, int> pi = pq.top();
            // cout<<pi.first<<" "<<pi.second<<endl; 
            pq.pop();
            ans.push_back(nums[-pi.second]);
        }
        return ans;
    }
};