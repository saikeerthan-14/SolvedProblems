class NumMatrix {
public:
    vector<vector<int>> myMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        
        int m= matrix.size(), n = matrix[0].size();
        //first row
        for(int i=1; i<n; i++)
            matrix[0][i] += matrix[0][i-1];
        //first col
        for(int i=1; i<m; i++)
            matrix[i][0] += matrix[i-1][0];
        //other parts of the matrix
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
        
        myMatrix = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        
        
        int sum = myMatrix[row2][col2];
        
        if(row1 > 0)
            sum -= myMatrix[row1-1][col2];
        if(col1 > 0)
            sum -= myMatrix[row2][col1-1];
        if(row1 > 0 && col1 > 0)
            sum += myMatrix[row1-1][col1-1];
        
        return sum;
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */