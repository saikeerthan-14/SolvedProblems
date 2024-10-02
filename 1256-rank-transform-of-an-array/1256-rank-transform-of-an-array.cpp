class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int>m;
        for(int i=0;i<arr.size();i++) {
            m[arr[i]] = i;
        }

        int cnt = 1;
        for(auto it: m) {
            m[it.first] = cnt;
            cnt++;
            // cout<<it.first<<" "<<m[it.first]<<endl;
        }
        for(int i=0;i<arr.size();i++) {
            // cout<<arr[i]<<" "<<m[arr[i]]<<endl;

            arr[i] = m[arr[i]];
        }
        return arr;
    }
};