// class Solution {
// public:
//     vector<int> maximumBeauty(vector<vector<int>>& nums, vector<int>& q) {
//         sort(nums.begin(), nums.end());
//         int i=0, ma = nums[0][0];
//         for(int j=0;j<nums.size();j++) {
//             if(nums[j][0]!=nums[i][0]) {
//                 i++;
//             }
//             nums[i][0] = nums[j][0];
//             ma = max(ma, nums[j][1]);
//             nums[i][1] = ma;
//         }
//         for(int i=0;i<nums.size();i++) {
//             cout<<"("<<nums[i][0]<<", "<<nums[i][1]<<"), ";
//         }
//         cout<<"\n";

//         nums.resize(i+1);
//         for(int i=0;i<nums.size();i++) {
//             cout<<"("<<nums[i][0]<<", "<<nums[i][1]<<"), ";
//         }
//         cout<<"\n";
//         vector<int> ans;
//         for(int i=0;i<q.size();i++) {
//             if(q[i]>=nums.back()[0]) {
//                 ans.push_back(nums.back()[1]);
//                 continue;
//             }
//             int it = lower_bound(nums.begin(), nums.end(), vector<int>{q[i], 0})-nums.begin();
//             cout<<it<<" - "<<q[i]<<" : "<<nums[it][0]<<", "<<nums[it][1]<<endl;
            
//             if(nums[it][0]==q[i]) ans.push_back(nums[it][1]);
//             else if(it>0)ans.push_back(nums[it-1][1]);
//             else ans.push_back(0);

//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        vector<int> ans(queries.size());
        // sort both items and queries in ascending order
        sort(items.begin(), items.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        vector<vector<int>> queriesWithIndices(queries.size(), vector<int>(2));

        for (int i = 0; i < queries.size(); i++) {
            queriesWithIndices[i][0] = queries[i];
            queriesWithIndices[i][1] = i;
        }

        sort(queriesWithIndices.begin(), queriesWithIndices.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int itemIndex = 0;
        int maxBeauty = 0;

        for (int i = 0; i < queries.size(); i++) {
            int query = queriesWithIndices[i][0];
            int originalIndex = queriesWithIndices[i][1];

            while (itemIndex < items.size() && items[itemIndex][0] <= query) {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }

            ans[originalIndex] = maxBeauty;
        }
        return ans;
    }
};