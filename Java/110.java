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
    
    public boolean isBalanced(TreeNode root) {
        if(root == null) return true;
        return searchHelper(root) == -1 ? false : true;
    }
    
    private int searchHelper(TreeNode root){
       
        if(root == null) return 0;
        int leftHeight = searchHelper(root.left);
        int rightHeight = searchHelper(root.right);
        
        // left and rigth must creater than one, difference not over 2
        if(leftHeight >= 0 && rightHeight >= 0 && Math.abs(leftHeight - rightHeight) <= 1){
            return Math.max(leftHeight, rightHeight) + 1;
        }
        else
            return -1;
            
        
    }
}