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
    bool workRecursive(TreeNode* root, long long left, long long right){
        if (!root) return 1;
        
        if (root->val > left && root->val < right)
            return workRecursive(root->left, left, root->val) && workRecursive(root->right, root->val, right);
        
        
        return 0;
    }
    
    
    bool isValidBST(TreeNode* root) {
        return workRecursive(root, INT64_MIN, INT64_MAX);
    }
};