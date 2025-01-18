class Solution {
public:
    int m, n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (unsigned int i = 0; i < board.size(); i++) 
            for (unsigned int j = 0; j < board[0].size(); j++) 
                if (dfs(board, i, j, word, 0))
                    return true;
        return false;
    }

bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx) {
    if(idx==word.size()) {
        return true;
    }
    
    if(i>=m || i<0 || j>=n || j<0 || board[i][j]!=word[idx]) return false;
    char c = board[i][j];
    board[i][j] = '*';
    bool ans = dfs(board, i+1, j, word, idx+1) || dfs(board, i-1, j, word, idx+1) || dfs(board, i, j+1, word, idx+1) || dfs(board, i, j-1, word, idx+1);
    board[i][j] = c;
    return ans;
}

};