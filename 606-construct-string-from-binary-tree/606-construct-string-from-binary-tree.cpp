/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    string res;
public:
    string tree2str(TreeNode* root) {
        res += to_string(root->val);
        if (root->left || root->right) {
            res += '(';
            if (root->left) tree2str(root->left);
            res += ')';
        }
        if (root->right) {
            res += '(';
            tree2str(root->right);
            res += ')';
        }
        return res;
    }
};