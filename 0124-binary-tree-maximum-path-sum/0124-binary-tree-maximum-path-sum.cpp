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
    int helper(TreeNode* root, int &maxi, int s) {
        if(!root) return 0;
        // s += root->val;
        int l = helper(root->left, maxi, s);
        int h = helper(root->right, maxi, s);
        if(l<0 ) l = 0;
        if(h<0 ) h = 0;
        
        // cout<<root->val<<" "<<l<<" "<<h<<endl;
        maxi = max(maxi, l + h + root->val);
        return root->val + max(l, h);
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxi = INT_MIN;
        helper(root, maxi, 0);
        return maxi;
    }
};

