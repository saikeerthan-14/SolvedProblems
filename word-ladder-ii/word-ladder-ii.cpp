class Solution {
public:
    void DFS(string start, string end, unordered_map<string, unordered_set<string>> &adj, vector<string>&a, vector<vector<string>> &ans) {
        a.push_back(start);
        if(start==end) {
            ans.push_back(a);
            a.pop_back();
            return;
        }
        for(string s: adj[start]) {
            DFS(s, end, adj, a, ans);
        }
        a.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        unordered_map<string, int> depth; 
        depth[beginWord] = 0;
        unordered_map<string, unordered_set<string>> adj;
        queue<string>q;
        q.push(beginWord);
        string temp, curr;
        while(!q.empty()) {
            curr = q.front();
            q.pop();
            temp = curr;
            // cout<<curr<<": ";
            for(int i=0;i<curr.size();i++) {
                for(char ch='a';ch<='z';ch++) {
                    if(curr[i]!=ch) {
                        temp[i] = ch;
                        if(s.find(temp)!=s.end()) {
                            
                            if(depth.find(temp) == depth.end()) {
                                depth[temp] = depth[curr] + 1;
                                adj[curr].insert(temp);
                                q.push(temp);
                                // cout<<temp<<" ";
                            } else if(depth[temp] == depth[curr]+1) {
                                adj[curr].insert(temp);
                            }
                        }
                    }
                }
                temp[i] = curr[i];
            }
            // cout<<endl;
        }
        // for(auto i: adj) {
        //     cout<<i.first<<" : ";
        //     for(string s: adj[i.first]) {
        //         cout<<s<<", ";
        //     }
        //     cout<<endl;
        // }
        vector<string> a;
        vector<vector<string>> ans;
        DFS(beginWord, endWord, adj, a, ans);
        return ans;
    }
};