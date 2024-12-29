class Solution {
public:
    struct Trie {
        Trie* children[26];
        string w;
        Trie (){
            for(int i=0;i<26;i++) children[i] = NULL;
            w = "";
        }
    };


    Trie* insert(vector<string>& words) {
        Trie* root = new Trie();
        for(int i=0;i<words.size();i++) {
            Trie* temp = root;
            for(char c: words[i]) {
                if(temp->children[c-'a'] == NULL) temp->children[c-'a'] = new Trie();
                temp = temp->children[c-'a'];
            }
            temp->w = words[i];
        }
        return root;
    }

    void helper(vector<vector<char>>& board, int i, int j, vector<string>&ans, Trie* temp) {
        char c = board[i][j];
        if(board[i][j]=='*') return;
        if(temp->children[c-'a']==NULL) {
            return;
        }
        temp = temp->children[c-'a'];
        if(temp->w!="") {
            ans.push_back(temp->w);
            temp->w = "";
        }
        board[i][j] = '*';
        if(i>0) helper(board, i-1, j, ans, temp);
        if(j>0) helper(board, i, j-1, ans, temp);
        if(i<board.size()-1) helper(board, i+1, j, ans, temp);
        if(j<board[0].size()-1) helper(board, i, j+1, ans, temp);
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* temp = insert(words);
        vector<string> ans;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                helper(board, i, j, ans, temp);
            }
        }
        return ans;
    }
};