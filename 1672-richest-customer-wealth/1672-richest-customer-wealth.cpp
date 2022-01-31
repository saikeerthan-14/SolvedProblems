class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        int sum,na_pilla=INT_MIN;
        for(int i=0;i<acc.size();i++) {
            sum=0;
            for(int j=0;j<acc[0].size();j++) {
                sum += acc[i][j];
            }
            na_pilla= max(na_pilla, sum);
        }
        int mamu = na_pilla;
        return mamu;
    }
};