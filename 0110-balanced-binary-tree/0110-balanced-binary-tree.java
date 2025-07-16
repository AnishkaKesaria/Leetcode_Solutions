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
    private int findHeight(TreeNode root) {
        if(root==null)
            return 0;
        int leftHeight = findHeight(root.left);
        int rightHeight = findHeight(root.right);

        return (1+Math.max(leftHeight,rightHeight));
    }

    public boolean isBalanced(TreeNode root) {
        if(root==null)
            return true;

        int leftHeight = 0, rightHeight = 0;
        if(root.left!=null)
            leftHeight = findHeight(root.left);
        if(root.right!=null)
            rightHeight = findHeight(root.right);

        if(Math.abs(leftHeight-rightHeight) <=1)
            return (true && (isBalanced(root.right) && isBalanced(root.left)));
        else
            return false;
    }
}