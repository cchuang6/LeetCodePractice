/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //middle
        if( (root->val - p->val) * (root->val - q->val) <= 0) return root;
        //left
        else if (root->val > p->val) return lowestCommonAncestor(root->left,p, q);
        //right
        else return lowestCommonAncestor(root->right, p, q);
    }
};