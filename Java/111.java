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
    public int minDepth(TreeNode root) {
        if(root == null) return 0;
        
        
        Stack<TreeNode> nodes = new Stack<>();
        Stack<Integer> levels = new Stack();
        
        nodes.push(root);
        levels.push(1);
        int min = Integer.MAX_VALUE;
        while(!nodes.empty()){
            TreeNode tempNode = nodes.pop();
            int tempLevel = levels.pop();
            
            //find leaf and update min
            if(tempNode.left == null && tempNode.right == null){
                    min = Math.min(min, tempLevel);
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
        return min;
    }
}