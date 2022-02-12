class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(s.find(endWord)==s.end()) return 0;
        if(s.find(beginWord)!=s.end()) s.erase(beginWord);
        queue<string> q;
        q.push(beginWord);
        
        string temp, curr;
        int lsize, depth = 0;
        while(!q.empty()) {
            depth += 1;
            lsize = q.size();
            // cout<<curr<<" : ";
            while(lsize--) {
                curr = temp = q.front();
                for(int i=0;i<curr.size();i++) {
                    for(char ch = 'a'; ch<='z';ch++) {
                        if(curr[i]!=ch) {
                            temp[i] = ch;
                            if(temp==endWord) return depth+1;
                            if(s.count(temp)) {
                                q.push(temp);
                                s.erase(temp);
                                // cout<<temp<<", ";
                            }
                        }
                    }
                    temp[i] = curr[i];
                }
                q.pop();
            }
            // cout<<endl;
            
        }
        return 0;
    }
};