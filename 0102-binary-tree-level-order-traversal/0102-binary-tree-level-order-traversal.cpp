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
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()){
            pair<TreeNode*, int> cur = q.front();
            q.pop();
            if (!cur.first)
                continue;
            if (res.size() <= cur.second)
                res.push_back({});
            int level = cur.second;
            
            res[level].push_back(cur.first->val);
            q.push({cur.first->left, level + 1});
            q.push({cur.first->right, level + 1});
        }
        
        return res;
    }
};