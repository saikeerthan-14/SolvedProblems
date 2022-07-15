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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, map<int, int>& inMap, int preorderStart, int inorderLeftMost, int inorderRightMost) {
        if(preorderStart >= preorder.size() || !(inMap[preorder[preorderStart]] >= inorderLeftMost && inMap[preorder[preorderStart]] <= inorderRightMost)) return nullptr;
        
        // make the value pointing to preorderStart as the root.
        TreeNode* root = new TreeNode(preorder[preorderStart]);
        
        // left child would have all the elements in the inorder list from inorderLeftMost to the (index of root) - 1
        // start of the left child would be the next element of the root. 
        // There is a chance that there is no left child. In that case termination condition would return nullptr as left child.
        root->left = buildTreeHelper(preorder, inorder, inMap, preorderStart+1, inorderLeftMost, inMap[root->val]-1);
        
        // right child would have all elements from (index of root) + 1 in the inorder list to the inorderRightMost.
        // start of the right child would be the next element of all the elements in the left subtree.
        // There is a chance that there is no right child. In that case termination condition would return nullptr as left child.
        root->right = buildTreeHelper(preorder, inorder, inMap, preorderStart+1+inMap[root->val]-inorderLeftMost, inMap[root->val]+1, inorderRightMost);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        
        // inorder list is used to get the number of elements in the subtree.
        // Once a root is picked from the preorder list, we use this map to determine the boundries of left and right childs.
        for(int i=0; i<inorder.size(); i++) {
            inMap.insert(make_pair(inorder[i], i));
        }
        
        // start building tree with all the elements in the preorder list.
        return buildTreeHelper(preorder, inorder, inMap, 0, 0, inorder.size()-1);
    }
};