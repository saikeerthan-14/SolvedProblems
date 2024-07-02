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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        int flag = 0, k;
        q.push(root);
        vector<vector<int>>ans;
        vector<int>v;
        while(!q.empty()) {
            k = q.size();
            while(k--) {
                TreeNode* f = q.front();
                q.pop();
                v.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            // if(flag) {
            //     reverse(v.begin(), v.end()); 
            //     flag = 0;
            // } else {
            //     flag = 1;
            // }

            ans.push_back(v);
            v.clear();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
