class Solution {
public:
    bool exist(vector<vector<char>> &board, int i, int j, string word, int pos){
    if(pos == -1) 
        return true;
        
    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '*')
        return false;
    
    if(word[pos] != board[i][j])
        return false;

    char temp = board[i][j];
    
    board[i][j] = '*';  // visited
    
    if(exist(board, i-1, j, word, pos-1) || exist(board, i+1, j, word, pos-1) || exist(board, i, j-1, word, pos-1) || exist(board, i, j+1, word, pos-1)){   
        board[i][j] = temp; // to store back the character for another word search
        return true;
    }
     
    board[i][j] = temp;  // backtrack
     
    return false;
}
 


vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int rows = board.size();
    int cols = board[0].size();
    
    int size = words.size();
    
    // Store the last character of every word in set
    set<char> s;
    for(int i=0; i<size; i++){
        string st = words[i];
        char ch = st[st.length()-1]; 
        s.insert(ch);
    }
    
    // store the last characters index pairs
    map<char,vector<pair<int,int>>> mp;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            char ch = board[i][j];
            if(s.find(ch) != s.end()){
                mp[ch].push_back({i,j}); 
            }
        }
    }
    
    // search for words starting from last charcter index pairs
    vector<string> ans;
    for(int i=0; i<size; i++){
        string st = words[i];
        char ch = st[st.length()-1];
        vector<pair<int,int>> v = mp[ch];
        for(int j=0; j<v.size(); j++){
            int x = v[j].first;
            int y = v[j].second;
            if(exist(board, x, y, st, st.length()-1)){
                ans.push_back(st);
                break;
            }
        }
    }
    return ans;
  
}
};