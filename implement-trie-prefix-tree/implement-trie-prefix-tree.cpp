class Trie {
private:
    Trie* next[26] = {};
    bool is_word = false;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char ch: word) {
            int i = ch-'a';
            if(!node->next[i]) {
                node->next[i] = new Trie();
            }
            node = node->next[i];
        }
        node->is_word = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char ch: word) {
            int i = ch-'a';
            if(!node->next[i]) {
                return false;
            }
            node = node->next[i];
        }
        return node->is_word;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char ch: prefix) {
            int i = ch-'a';
            if(!node->next[i]) {
                return false;
            }
            node = node->next[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */