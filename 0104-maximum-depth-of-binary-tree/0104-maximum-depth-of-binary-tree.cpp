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
    int maxDepth(TreeNode* root) {
        deque<pair<TreeNode*, int>> dq;
        dq.push_back({root, 0});
        int mx = 0;
        
        while (dq.size()){
            pair<TreeNode*, int> cur = dq.front();       
            dq.pop_front();
            if (cur.first == nullptr)
                continue;
            mx = max(mx, cur.second + 1);
            dq.push_back({cur.first->left, cur.second + 1});
            dq.push_back({cur.first->right, cur.second + 1});

        }
        return mx;
        
    }
};