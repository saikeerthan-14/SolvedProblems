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
    TreeNode *Tree(vector<int>& in, int x, int y,vector<int>& po,int a,int b){
        if(x>y || a>b) return nullptr;
        TreeNode* n = new TreeNode(po[b]);
        int si = x;
        while(n->val != in[si]) si++;
        n->left = Tree(in, x, si-1, po, a, a+si-x-1);
        n->right = Tree(in, si+1, y, po, a+si-x, b-1);
        return n;
        
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
        return Tree(in,0,in.size()-1,po,0,po.size()-1);
    }
};