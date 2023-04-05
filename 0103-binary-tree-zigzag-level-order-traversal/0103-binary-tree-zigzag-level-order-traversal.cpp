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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        if (!root) return sol;
        
        queue<TreeNode*> q;
        q.push(root);
        bool lToR = true;
        while (!q.empty()){
            int sz = q.size();
            vector<int> res(sz);
            for (int i = 0; i < sz; i++){
                TreeNode* cur = q.front(); q.pop();
                if (lToR)
                    res[i] = cur->val;
                else
                    res[sz - i - 1] = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            lToR = !lToR;
            sol.push_back(res); 
        }
        
        
        
        return sol;
    }
};