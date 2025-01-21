class Solution {
public:
    int r, c;
    void dfs(int i, int j, vector<vector<char>>& board) {
        if(i<0 || j<0 || i>=r || j>=c) return;
        // cout<<i<<", "<<j<<" - ";
        if(board[i][j]=='O') {
            board[i][j] = 'S';
            dfs(i-1, j, board);
            dfs(i, j-1, board);
            dfs(i+1, j, board);
            dfs(i, j+1, board);
        }

        // cout<<endl;
        return;
    }

    void solve(vector<vector<char>>& board) {
        r = board.size(), c = board[0].size();
        // cout<<"1col - ";
        for(int i=0;i<r;i++) {
            if(board[i][0]=='O') {
                dfs(i, 0, board);
            }
        }
        // cout<<"\n=====\n";
        // cout<<"lastcol - ";

        for(int i=0;i<r;i++) {
            if(board[i][c-1]=='O') {
                dfs(i, c-1, board);
            }
        }
        // cout<<"\n=====\n";

        // cout<<"1row - ";

        for(int i=0;i<c;i++) {
            if(board[0][i]=='O') {
                dfs(0, i, board);
            }
        }
        // cout<<"\n=====\n";
        // cout<<"lastrow - ";

        for(int i=0;i<c;i++) {
            if(board[r-1][i]=='O') {
                dfs(r-1, i, board);
            }
        }
        // cout<<"\n=====\n";


        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(board[i][j]=='S') {
                    board[i][j] = 'O';
                } else if(board[i][j]=='O') {
                    board[i][j] = 'X';
                }
                // cout<<board[i][j]<<" "; 
            }
            cout<<endl;
        }
    }
};