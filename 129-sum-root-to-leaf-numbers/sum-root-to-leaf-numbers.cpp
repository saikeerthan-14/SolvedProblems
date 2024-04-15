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
    void helper(TreeNode* root, int sum, int& ans) {
        if(root==NULL) return;
        if(root && root->left==NULL && root->right==NULL) {
            // cout<<root->val;
            ans += sum*10+root->val;
            // cout<<" "<<ans<<"\n";
            return;
        }
        helper(root->left, sum*10+root->val, ans);
        helper(root->right, sum*10+root->val, ans);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0, sum = 0;
        helper(root, sum, ans);
        return ans;
    }
};