#define pii pair<int, int>
class Solution {
public:

    static bool compare(pii &a, pii &b ) {
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int>u;
        priority_queue<pii, vector<pii>, decltype(&compare)>pq(compare);
        for(int i=0;i<nums.size();i++) u[nums[i]]++;
        for(auto it=u.begin();it!=u.end();it++) {
            pq.push({it->second, it->first});
        }
        while(!pq.empty()) {
            pii p = pq.top();
            pq.pop();
            for(int i=0;i<p.first;i++) {
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};