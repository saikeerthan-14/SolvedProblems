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
    void helper(TreeNode *root, string s, string& ans) {
        if(root==NULL) return;
        s.push_back(char('a'+root->val));
        if(root->left == NULL && root->right == NULL) {
            reverse(s.begin(), s.end());
            if(ans.empty() || s<ans) {
                ans = s;
            }
            reverse(s.begin(), s.end());
        }
        helper(root->left, s, ans);
        helper(root->right, s, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        helper(root, "", ans);
        return ans;
    }
};