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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        double s=0, c=0;
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if(t==NULL) {
                ans.push_back(s/c);
                s=c=0;
                if(!q.empty()) q.push(NULL);
            } else {
                s += t->val;
                c++;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                
            }
 
        }
        return ans;
    }
};