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
    private void findPaths(TreeNode root, int targetSum, List<List<Integer>> ans, int currSum, List<Integer> currPath) {
        if(root==null)
            return;

        currSum += root.val;
        currPath.add(root.val);

        if(root.left==null && root.right==null) {
            if(currSum == targetSum) 
                ans.add(new ArrayList(currPath));
        } else {
            findPaths(root.left, targetSum, ans, currSum, currPath);
            findPaths(root.right, targetSum, ans, currSum, currPath);
        }

        currSum -= root.val;
        currPath.remove(currPath.size()-1);
        return;
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new ArrayList();
        List<Integer> currPath = new ArrayList();
        findPaths(root, targetSum, ans, 0, currPath);
        return ans;
    }
}