struct TrieNode {

    TrieNode *children[26];
    bool flag;
    TrieNode() {
        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
        flag = false;
    }
};

class Trie { 
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++) {
            if(temp->children[word[i]-'a']==NULL) {
                temp->children[word[i]-'a'] = new TrieNode();
            }
            temp = temp->children[word[i]-'a'];
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++) {
            if(temp->children[word[i]-'a']==NULL) {
                // temp->children[word[i]-'a'] = new TrieNode();
                return false;
            }
            temp = temp->children[word[i]-'a'];
        }
        return temp->flag;
    }
    
    bool startsWith(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++) {
            if(temp->children[word[i]-'a']==NULL) {
               return false;
                // temp->children[word[i]-'a'] = new TrieNode();
            }
            temp = temp->children[word[i]-'a'];
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