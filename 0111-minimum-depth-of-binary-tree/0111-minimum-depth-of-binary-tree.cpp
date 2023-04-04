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
    int work(TreeNode* root){
        if (!root) return 1e6;
        if (!root->left && !root->right){
            return 1;
        }
        return min(work(root->left), work(root->right)) + 1;
    }
    int minDepth(TreeNode* root) {
        int ans = work(root);
        return ans >= 1e6 ? 0 : ans;
    }
};