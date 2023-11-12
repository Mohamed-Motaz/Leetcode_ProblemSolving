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
    int res = 0;

    int maxPathSum(TreeNode* root) {
        res = root->val;
        solve(root);
        return res;
    }
    
    //each branch is responsible for not splitting, but returning the max path only
    int solve(TreeNode* root){
        if (!root) return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        res = max({res, root->val, root->val + left, root->val + right});
        res = max(res, root->val + left + right);
        return max({root->val, root->val + left, root->val + right});
    }
};