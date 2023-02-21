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

int work(TreeNode* node, int mx){
    if (node == nullptr) return 0;
    
    if (node->val >= mx)
        return 1 + work(node->left, node->val) + work(node->right, node->val);
    else
        return work(node->left, mx) + work(node->right, mx);

}

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return work(root, INT32_MIN);
    }
};