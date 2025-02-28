/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null,"; 
        queue<TreeNode*> q;
        q.push(root);
        string s = to_string(root->val);
        // vector<char> v;
        
        s.push_back(',');
        while(!q.empty()) {
            TreeNode* f = q.front();
            q.pop();

            if(f->left) {
                q.push(f->left);
                s.append(to_string(f->left->val));
                s.push_back(',');

            } else {
                s.append("null,");
            }
            if(f->right) {
                q.push(f->right);
                s.append(to_string(f->right->val));
                s.push_back(',');
            } else {
                s.append("null,");
            }
        }
        // cout<<s<<endl;
        return s;
    }

    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="null,") return NULL;
        vector<string> data_list;
        stringstream ss(data);
        string token;

        // Split string by commas
        while (getline(ss, token, ',')) {
            data_list.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(data_list[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i=1, nn=data_list.size();
        while(!q.empty()) {
            TreeNode* n =  q.front();
            q.pop();

            if(i<nn && data_list[i] != "null") {
                n->left = new TreeNode(stoi(data_list[i]));
                q.push(n->left);
            } 
            i++;

            if(i<nn && data_list[i] != "null") {
                n->right = new TreeNode(stoi(data_list[i]));
                q.push(n->right);
            } 
            i++;
        }

        return root;
        // return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));