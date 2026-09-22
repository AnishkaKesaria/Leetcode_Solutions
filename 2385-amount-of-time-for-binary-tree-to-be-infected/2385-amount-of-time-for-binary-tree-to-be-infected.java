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
    public int amountOfTime(TreeNode root, int start) {
        HashMap<TreeNode, TreeNode> parentMap = new HashMap<>();
        Queue<TreeNode> q = new LinkedList<>();
        Set<TreeNode> burntSet = new HashSet<>();
        TreeNode startNode = new TreeNode();
        q.offer(root);
        while(!q.isEmpty()) {
            TreeNode top = q.poll();
            if(top.val==start) {
                startNode = top;
                burntSet.add(startNode);
            }
            if(top.left!=null) {
                q.offer(top.left);
                parentMap.put(top.left, top);
            }
            if(top.right!=null){
                q.offer(top.right);
                parentMap.put(top.right, top);
            }
        }


        int time = 0;
        boolean burnt = false;
        q.offer(startNode);
        while(!q.isEmpty()) {
            burnt = false;
            int adjacentCount = q.size();
            System.out.println(adjacentCount);
            for(int i=0; i<adjacentCount; i++) {
            TreeNode top = q.poll();
            if(top.left!=null && !burntSet.contains(top.left)) {
                q.offer(top.left);
                burntSet.add(top.left);
                burnt = true;
            }
            if(top.right!=null && !burntSet.contains(top.right)) {
                q.offer(top.right);
                burntSet.add(top.right);
                burnt = true;
            }
            if(parentMap.get(top)!=null) {
                TreeNode parent = parentMap.get(top);
                if(!burntSet.contains(parent)) {
                    q.offer(parent);
                    burntSet.add(parent);
                    burnt = true;
                }
            }
            }

            if(burnt==true)
                time++;
            
        }

        return time;
    }
}