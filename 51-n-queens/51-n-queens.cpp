class Solution {
public:
    // function to check whether position of queen you put on board is allowed or not
    bool isValidpos(vector<string>&board,int row,int col)
    {
        // if present on same column
        for(int i=row-1;i>=0;i--)
        {
            if(board[i][col]=='Q')
            {
                return false;
            }
        }
        // checking for upper left diagonal
        for(int i = row-1,j = col-1;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        // checking for upper right diagonal
        for(int i = row-1,j = col+1;i>=0 && j<board.size();i--,j++)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
    void backtrack(vector<string>&board,int row,vector<vector<string>>&v)
    {
        // if row is equal to board size then return that 2D array
        if(row == board.size())
        {
             v.push_back(board);
             return;
        }
        // placing queen on each row
        // also can be done by each column also
        for(int j = 0;j<board.size();j++)
        {
            if(isValidpos(board,row,j))
            {
                board[row][j]='Q';
                backtrack(board,row+1,v);
                // backtrack 
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>>v;
        backtrack(board,0,v);
        return v;
    }
};