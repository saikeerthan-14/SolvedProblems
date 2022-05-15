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
    
    int deepestLeavesSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        if(root)
        {
            q.push(root);
        }
        
        int level = 1;
        
        int sum = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            int flag = 0;
            
            int aux = 0;
            
            for(int i=0;i<sz;i++)
            {
                TreeNode* node = q.front();
                
                q.pop();
                
                if(node->left){ q.push(node->left); flag = 1; }
                if(node->right){ q.push(node->right); flag = 1; }
                
                aux+=node->val;
            }
            
            if(flag==0)
            {
                sum+=aux;
            }
        }
        
        return sum;
    }
};