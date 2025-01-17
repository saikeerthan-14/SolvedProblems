/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> u;
        queue<Node*>   q;
        q.push(node);
        while(!q.empty()) {
            int k = q.size();
            while(k--) {
                Node* k = q.front();
                q.pop();
                if(u.find(k)==u.end()) {
                    u[k] = new Node(k->val);
                }
                // cout<<k->val<<" "<<k->neighbors.size()<<endl;
                for(int i=0;i<k->neighbors.size();i++) {
                    Node* neigh = k->neighbors[i];
                    if(u.find(neigh)==u.end()) {
                        u[neigh] = new Node(neigh->val);
                        q.push(k->neighbors[i]);
                    }
                    u[k]->neighbors.push_back(u[neigh]);
                    
                }
            }
        }
        return u[node];
    }
};