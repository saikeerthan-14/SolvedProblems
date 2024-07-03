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

    int helper(TreeNode* root, int& h) {
        if(!root) return 0;
        int l1 = helper(root->left, h);
        int h1 = helper(root->right, h);
        h = max(h, l1+h1);
        return 1 + max(l1, h1);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        helper(root, ans);

        return ans;
    }
};