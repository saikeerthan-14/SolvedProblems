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
    void calculate(TreeNode* root, int tillSum) {
        if(root->left==NULL && root->right==NULL) {
            sum += tillSum;
            return;
        }
        if(root->left)
            calculate(root->left, tillSum*10+root->left->val);
        if(root->right)
            calculate(root->right, tillSum*10+root->right->val);
        
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        calculate(root, root->val);
        return sum;
    }
};