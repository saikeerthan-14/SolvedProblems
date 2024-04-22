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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty()) {
            TreeNode* t = q.front();
            
            q.pop();
            if(t==NULL) {
                ans.push_back(v);
                v = {};
                if(!q.empty()) q.push(NULL);
            } else {
                v.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                
            }
 
        }
        return ans;
    }
};