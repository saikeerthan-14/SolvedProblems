/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL) return {};
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty()) {
            Node* t = q.front();
            
            q.pop();
            if(t==NULL) {
                ans.push_back(v);
                v={};
                if(!q.empty()) q.push(NULL);
            } else {
                v.push_back(t->val);
                for(int i=0;i<(t->children).size();i++) {
                    if((t->children)[i])
                        q.push((t->children)[i]);
                }
            }
 
        }
        return ans;
    }
};

