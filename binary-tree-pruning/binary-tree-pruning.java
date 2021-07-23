/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean check(TreeNode r) {
        if(r.left == null && r.right == null && r.val == 0) return true;
        return false;
    }
    public TreeNode pruneTree(TreeNode root) {
        if(root==null) return root;
        root.left = pruneTree(root.left);
        root.right = pruneTree(root.right);
        if(check(root)) {
            return null;
        }
        return root;
    }
}