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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()){
            int qSize = q.size();
            int last = -101;
            for (int i = 0; i < qSize; i++){
                TreeNode* par = q.front();
                q.pop();
                if (!par) continue;
                q.push(par->left);
                q.push(par->right);
                last = par->val;
            }
            if (last != -101) res.push_back(last);
        }
        return res;
    }
};