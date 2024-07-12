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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pr, int ins, int ine, unordered_map<int, int>&u) {
        if(pr >= preorder.size() || u[preorder[pr]] < ins || u[preorder[pr]] > ine) return nullptr;

        TreeNode* root = new TreeNode(preorder[pr]);
        root->left = helper(preorder, inorder, pr+1, ins, u[root->val]-1, u);
        root->right = helper(preorder, inorder, pr+1+u[root->val]-ins, u[root->val]+1, ine, u);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> u;
        for(int i=0;i<inorder.size();i++) 
            u[inorder[i]] = i;
        return helper(preorder, inorder, 0, 0, inorder.size()-1, u);
    }
};