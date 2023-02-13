/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
            int children = q.size();
            vector<int> cur;
            for (int i = 0; i < children; i++){
                TreeNode* c = q.front(); q.pop();
                cur.push_back(c->val);
                if (c->left)
                    q.push(c->left);
                if (c->right)
                    q.push(c->right);
            }
            res.push_back(cur);
        }
        
        return res;
    }
};