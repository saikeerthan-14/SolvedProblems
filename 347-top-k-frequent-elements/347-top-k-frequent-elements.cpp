class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>u;
        for(int i:nums) u[i]++;
        auto comp = [&u](auto &lhs, auto &rhs) {
              return u[lhs] > u[rhs];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);    
        for(auto i:u) {
            pq.push(i.first);
            if(pq.size()>k) pq.pop();
         }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top()); pq.pop();
        }
        return ans;
    }
};