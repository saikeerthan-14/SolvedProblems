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
  int sumRootToLeaf(TreeNode *root) {
    dfs(root, "");
    int ans = 0;
    for (auto num : nums) {
      ans += stoi(num, nullptr, 2);
    }
    return ans;
  }

 private:
  vector<string> nums;
  void dfs(TreeNode *node, string curr) {
    curr += to_string(node->val);
    if (!node->left && !node->right) {
      nums.push_back(curr);
      return;
    }
    if (node->left) dfs(node->left, curr);
    if (node->right) dfs(node->right, curr);
  }
};