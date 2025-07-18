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
    private TreeNode findPredecesor(TreeNode root) {
        while(root.right!=null) {
            root = root.right;
        }
        return root;
    }

    public TreeNode deleteNode(TreeNode root, int key) {
        if(root==null)
            return null;

        if(root.val>key)
            root.left = deleteNode(root.left, key);
        else if (root.val<key)
            root.right = deleteNode(root.right, key);
        else{
            if(root.left==null && root.right==null) {
                return null;
            }
            
            else if(root.left==null && root.right!=null) {
                return root.right;
            }

            else if(root.left!=null && root.right==null) {
                return root.left;
            }

            else {
                TreeNode predecesor = findPredecesor(root.left);
                root.val = predecesor.val;
                root.left = deleteNode(root.left, predecesor.val);
            }
        } 
        return root;
    }
}