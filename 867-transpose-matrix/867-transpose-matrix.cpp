class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n = matrix[0].size(); 
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int>temp(m,0);
            ans.push_back(temp);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                ans[j][i] = matrix[i][j];
        }
        return ans;
    }
};