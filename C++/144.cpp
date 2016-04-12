/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    //Morrison Traversal
    vector<int> preorderTraversal(TreeNode *root) {
        struct TreeNode* cur;
        struct TreeNode* prev = NULL;
        vector<int> result;
        cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                result.push_back(cur->val);
                cur = cur->right;
            }
            else{
                //find the go back node
                prev = cur->left;
                while(prev->right != NULL && prev->right != cur)
                    prev = prev->right;
                if(prev->right == NULL){
                    result.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return result;
        
    }
};