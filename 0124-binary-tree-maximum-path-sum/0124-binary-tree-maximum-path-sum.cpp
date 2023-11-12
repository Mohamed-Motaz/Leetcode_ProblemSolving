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
    int res = INT32_MIN;

    int maxPathSum(TreeNode* root) {
        solve(root);
        return res;
    }
    
    //each branch is responsible for not splitting, but returning the max path only
    int solve(TreeNode* root){
        if (!root) return 0;
        
        int left = max(solve(root->left), 0); //can take or leave
        int right = max(solve(root->right), 0);
        
        res = max({
            res,
            root->val + left + right
        });
        
        return root->val + max(left, right);
    }
};