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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //using queue
        if(!root)
            return{};
        vector<int> levelResult;
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while(!q.empty()){
            if(q.front()->left)  {q.push(q.front()->left);}
            if(q.front()->right) {q.push(q.front()->right);}
            
            levelResult.push_back(q.front()->val);
            q.pop();
            if(--count == 0){
                result.push_back(levelResult);
                levelResult.clear();
                count = q.size();
            }
        }
        return result;
    }
    
};