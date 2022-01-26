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
    vector<int> ans;
    
    void inOrder(TreeNode* root, vector<int>& ans) {
        if(root==NULL) return;
        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inOrder(root1, ans);
        inOrder(root2, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};