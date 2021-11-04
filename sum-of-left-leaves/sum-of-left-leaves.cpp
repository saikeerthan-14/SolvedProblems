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
    int sum = 0;
    void helper(TreeNode* root, TreeNode* par) {
        if(root->left==NULL && root->right==NULL && par->left==root) {
            // cout<<root->val<<endl;
            sum += root->val;
            return;
        }
        if(root->left) helper(root->left, root);
        if(root->right) helper(root->right, root);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        helper(root, root);
        return sum;
    }
};