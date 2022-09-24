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
    void generate(int s, TreeNode* root, int t, vector<int>v, vector<vector<int>>&ans) {
        if(!root) return;
        v.push_back(root->val);
        if(root->left == NULL && root->right==NULL) {
            if(s+root->val==t) {
                ans.push_back(v);
                return;
            }
        }
        // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        // cout<<"; "<<s<<endl;
        
        generate(s+root->val, root->left, t, v, ans);
        generate(s+root->val, root->right, t, v, ans);
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> v;
        generate(0,root, targetSum, v, ans);
        return ans;
    }
};