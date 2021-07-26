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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return nullptr;
        if(n==1) return new TreeNode(nums[0]);
        // if(r==-100) r = n-1;
        int m = n/2;
        TreeNode* root = new TreeNode(nums[m]);
        vector<int>lf (nums.begin(), nums.begin()+m);
        vector<int>rf (nums.begin()+m+1, nums.end());
        root->left = sortedArrayToBST(lf);
        root->right = sortedArrayToBST(rf);
        return root;
    }
};