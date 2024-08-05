class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> u;
        for(int i=0;i<arr.size();i++) {
            u[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++) {
            if(u[arr[i]]==1) k--;
            if(k==0) return arr[i];
        }
        return "";

    }
};