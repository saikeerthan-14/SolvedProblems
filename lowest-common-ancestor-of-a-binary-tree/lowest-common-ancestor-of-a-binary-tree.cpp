/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool find(TreeNode* root, TreeNode* t) {
        if(!root) return false;
        if(root == t) return true;
        return find(root->left, t) || find(root->right, t);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(find(root, p) && find(root, q)) {
            while(root) {
                if(find(root->left, p) && find(root->left, q)) {
                    root = root->left;
                } else if(find(root->right, p)&&find(root->right, q)) {
                    root = root->right;
                } else 
                    break;
            }
            return root;
        } else {
            return nullptr;
        }
    }
};