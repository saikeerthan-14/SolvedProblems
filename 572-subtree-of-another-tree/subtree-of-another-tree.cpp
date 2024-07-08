// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>& v) {
//         if(!root) return;
//         inorder(root->left, v);
//         v.push_back(root->val);
//         inorder(root->right, v);
//     }
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         vector<int> r1, s1;
//         inorder(root, r1);
//         inorder(root, s1);
//         int j = 0;
//         for(int i=0;i<r1.size();i++) {
//             if(r1[i]==s1[j]) {
//                 continue
//             }
//         }
//         return false;
//     }
// };
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
    
    bool helper(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return true;
        // if(!r1 || !r2) return false;
        // if(r1->val != r2->val) return false;
        // return helper(r1->left, r2->left) && helper(r1->right, r2->right);
        if(r1 && r2 && r1->val == r2->val) {
            return helper(r1->left, r2->left) && helper(r1->right, r2->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* r1, TreeNode* r2) {
        if(!r2) return true;
        if(!r1) return false;
        // if(helper(r1, r2)) return true;
        return helper(r1, r2) || isSubtree(r1->left, r2) || isSubtree(r1->right, r2);
    }
};
