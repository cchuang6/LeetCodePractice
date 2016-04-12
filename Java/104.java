/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null) return 0;
        
        int max = 0;
        Stack<Integer> levels = new Stack<>();
        Stack<TreeNode> nodes = new Stack<>();
        
        nodes.push(root);
        levels.push(1);
        
        while(!nodes.empty()){
            int tempLevel = levels.pop();
            TreeNode tempNode = nodes.pop();
            if(tempNode.left == null && tempNode.right == null){
                max = Math.max(max, tempLevel);
            }
            else{
                if(tempNode.left != null){
                    nodes.push(tempNode.left);
                    levels.push(tempLevel + 1);
                }
                if(tempNode.right != null){
                    nodes.push(tempNode.right);
                    levels.push(tempLevel + 1);
                }
            }
        }
        
        return max;
    }
}