class Solution {
public:
    vector<vector<int>>ans;
    void solve(int cnt,int idx,int k,int n,vector<int> &t){
        if(t.size() > k || idx > 10)return;
        if(cnt == n && t.size() == k){
            ans.push_back(t);
            return;
        }
        else if(cnt < n){
            cnt += idx;
            t.push_back(idx);
            solve(cnt,idx + 1,k,n,t);
            t.pop_back();
            cnt -= idx;
            solve(cnt,idx + 1,k,n,t);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(0,1,k,n,temp);
        return ans;
    }
};