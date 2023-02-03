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
    void w(TreeNode *node)
    {
        if (!node || (!node->left && !node->right))
            return;
        swap(node->left, node->right);
        w(node->left);
        w(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *copy = root;
        w(root);
        return copy;
    }
};