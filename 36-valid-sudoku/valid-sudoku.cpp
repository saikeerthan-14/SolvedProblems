class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>>r;
        unordered_map<int, unordered_set<char>>c;
        unordered_map<int, unordered_set<char>>s;

        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                char p = board[i][j];
                if(p!='.') {
                    if(r[i].count(p) || c[j].count(p) || s[(i/3)*3 + (j/3)].count(p)) return false;
                    r[i].insert(p);
                    c[j].insert(p);
                    s[(i/3)*3 + (j/3)].insert(p);
                }
            }
        }
        return true;
    }
};
