struct Trie {
    Trie *children[26];
    bool flag;
    Trie() {
        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
        flag = false;
    }
};

class WordDictionary {
public:
    Trie *root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *temp = root;
        for(char ch: word) {
            if(temp->children[ch-'a']==NULL) {
                temp->children[ch-'a'] = new Trie();
            }
            temp = temp->children[ch-'a'];
        }
        temp->flag = true;
    }

    bool helperSearch(string word, Trie *root) {
        Trie *temp = root;
        for(int i=0;i<word.size();i++) {
            char ch = word[i];
            // cout<<ch<<endl;
            if(ch!='.') {
                if(temp->children[ch-'a']==NULL) {
                    return false;
                }
                temp = temp->children[ch-'a'];
            } else {
                for(int j=0;j<26;j++) {
                    if(temp->children[j]!=NULL && helperSearch(word.substr(i+1), temp->children[j])) {
                        return true;
                    }
                }
                return false;
            }
        }
        return temp->flag;
    }
    
    bool search(string word) {
        bool res = helperSearch(word, root);
        // cout<<"======="<<res<<"=======\n";
        return res;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */