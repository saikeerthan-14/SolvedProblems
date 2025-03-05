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
    void helper(TreeNode* root, int &ans, int maz) {
        if(!root) return;
        if(root->val>=maz) {
            // cout<<root->val<<maz<<endl;
            ans++;
            maz = max(maz, root->val);
        }
        helper(root->left, ans, maz);
        helper(root->right, ans, maz);
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        int maz = INT_MIN;
        helper(root, ans, maz);
        
        return ans;
    }
};