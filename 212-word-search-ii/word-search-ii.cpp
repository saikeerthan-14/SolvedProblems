// class Solution {
// public:
//     bool isValid(int i, int j, int m, int n) {
//         if(i<0 || i>=m || j<0 || j>=n) return false;
//         return true;
//     }

//     void helper(vector<vector<char>>& board, string& word, vector<string>& ans, int st, string &s, int m, int n) {
//         if(st==word.size()) {
//             if(s==word) ans.push_back(word);
//             return;
//         }
//         vector<pair<int, int>> dire = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//         for(int i=0;i<dire.size();i++) {

//         }
//     }

//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         vector<string> ans;
//         string s;
//         for(int i=0;i<words.size();i++)
//             helper(board, words[i], ans, 0, s, board.size(), board[0].size());
//         return ans;    
//     }
// };

class Solution {
public:

    string str;
    bool vis[13][13];

    unordered_set<string> res;
    unordered_set<string> toFound;
    unordered_map<string, int> m;

    void rec(int i, int j, vector<vector<char>> &a)
    {
        if (toFound.find(str) != toFound.end())
        {
            string curr;

            for (auto x : str)
            {
                curr += x;
                m[curr]--;
            }

            toFound.erase(curr);
            res.insert(str);
        }

        if (i < 0 || j < 0 || i >= a.size() || j >= a[0].size() || vis[i][j] || m[str] == 0)
        {
            return;
        }

        vis[i][j] = 1;

        str += a[i][j];

        rec(i + 1, j, a);
        rec(i, j + 1, a);
        rec(i, j - 1, a);
        rec(i - 1, j, a);

        vis[i][j] = 0;

        str.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& a, vector<string>& words) {


        for (auto x : words)
        {
            string curr;

            toFound.insert(x);

            for (auto y : x)
            {
                curr += y;
                m[curr]++;
            }
        }

        m[""]++;

        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[0].size(); j++)
            {
                memset(vis, 0, sizeof(vis));
                rec(i, j, a);
            }
        }

        vector<string> ans;

        for (auto x : res)
        {
            ans.push_back(x);
        }

        return ans;
    }
};