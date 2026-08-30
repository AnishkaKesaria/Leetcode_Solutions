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
    private void fillStack(Stack<TreeNode> st, TreeNode root) {
        if(root==null)
            return;

        st.push(root);
        
        if(root.left!=null)
            fillStack(st, root.left);


        if(root.right!=null)
            fillStack(st, root.right);

        return;
    }

    public void flatten(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        fillStack(st, root);

        TreeNode newNode = null;
        TreeNode lastNode = null;

        while(!st.isEmpty()) {
            newNode = st.pop();
            newNode.right = lastNode;
            newNode.left = null;

            lastNode = newNode;
        }

        return;
    }
}