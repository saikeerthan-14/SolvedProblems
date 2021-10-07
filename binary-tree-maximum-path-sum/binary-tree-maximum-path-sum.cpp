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
private:
   int maxPath(TreeNode* root, int& d) {
       if(root==NULL) return 0;
       int l = max(0, maxPath(root->left, d));
       int r = max(0, maxPath(root->right, d));
       d = max(d, root->val + l + r);
       return root->val + max(l, r);
   } 
public:
    int maxPathSum(TreeNode* root) {
        int d = INT_MIN;
        maxPath(root, d);
        return d;
    }
};