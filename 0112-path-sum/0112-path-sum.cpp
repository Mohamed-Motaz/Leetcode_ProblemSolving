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
    bool work(TreeNode* node, int cur, int targetSum){
        if (!node) return 0;
        if (!node->right && !node->left){
            return cur + node->val == targetSum;
        }
        
        return work(node->left, cur + node->val, targetSum) 
            || work(node->right, cur + node->val, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return work(root, 0, targetSum);
    }
};