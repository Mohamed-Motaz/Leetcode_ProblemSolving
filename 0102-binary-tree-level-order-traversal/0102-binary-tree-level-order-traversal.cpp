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
        if (root == nullptr ) return res;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
            const int n = q.size();
            vector<int> v(n);
            for (int i = 0; i < n; i++){
                TreeNode* par = q.front(); q.pop();
                if (par->left) q.push(par->left);
                if (par->right) q.push(par->right);
                v[i] = par->val;
            }
            res.push_back(v);
        }
        
        return res;
    }
};