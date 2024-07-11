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
public:
    bool helper(TreeNode* root, long long mi, long long ma) {
        if(!root) return true;
        // // bool l = helper(root->left, min(mi, root->val));
        // bool l = helper(root->left, min(mi, root->val));
        // bool h = helper(root->right, min(mi, root->val));
        // // bool r = helper(root->right, min(mi, root->val));

        // if(l<h)

        // return l&&r;
        if(root->val<=mi ||root->val >= ma) return false;
        return helper(root->left, mi, root->val) && helper(root->right, root->val, ma);

    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        // TreeNode* prev = NULL;
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};