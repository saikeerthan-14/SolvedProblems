// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Codec {
// public:
//     void preorder(TreeNode* root, string &s) {
//         if(!root) {
//             s.push_back('#');
//             s.push_back(' ');
//         } else {
//             s += to_string(root->val);
//             s.push_back(' ');
//             preorder(root->left, s);
//             preorder(root->right, s);
//         }
//     }
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         string s="";
//         preorder(root, s);
//         // cout<<s<<endl;
//         return s;
//     }

//     // TreeNode* make_tree(vector<string> v, int& i) {
//     //     if(v[i]=="#") return NULL;
//     //     int l = stoi(v[i]);
//     //     TreeNode* root = new TreeNode(l);
//     //     root->left = make_tree(v, ++i);
//     //     root->right = make_tree(v, ++i);
//     //     return root;
//     // }
//     // // Decodes your encoded data to tree.
//     // TreeNode* deserialize(string s) {
//     //     vector<string> v;
//     //     int j;
//     //     for(int i=0;i<s.size();) {
//     //         j = i;
//     //         while(s[j]!=' ') j++;
//     //         v.push_back(s.substr(i, j-i));
//     //         i = j+1;
//     //         // cout<<v.back()<<endl;
//     //     }
//     //     j = 0;
//     //     return make_tree(v, j);
//     // }
//     // Decodes your encoded data to tree.
    
// };

// // Your Codec object will be instantiated and called as such:
// // Codec ser, deser;
// // TreeNode* ans = deser.deserialize(ser.serialize(root));
class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};