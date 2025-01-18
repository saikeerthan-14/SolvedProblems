class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& carr, int ts) {
        vector<vector<int>>ans;
        vector<int>ds;
        int idx=0;
        int N=carr.size();
        sort(carr.begin(),carr.end());
        solve(idx,ts,ans,ds,carr,N);
        return ans;
    }
    void solve(int idx,int ts,vector<vector<int>>&ans,vector<int>&ds,vector<int>&carr,int N) {
        if(ts==0) {
            ans.push_back(ds);
            return;
        }
        if(idx==N) {
            return;
        }
        for(int i=idx;i<N;i++) {
            if(i>idx && carr[i]==carr[i-1]) continue;
            if(carr[i]<=ts) {
                ds.push_back(carr[i]);
                solve(i+1,ts-carr[i],ans,ds,carr,N);
                ds.pop_back();
            }
            else{
                return;
            }
        }
    }
    
};