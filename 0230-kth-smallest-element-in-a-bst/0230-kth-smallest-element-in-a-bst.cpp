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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        solve(root, k, res);
        return res;
    }
    
    void solve(TreeNode* root, int& k, int& res){
        if (!root)
            return;
        
        solve(root->left, k, res);
        k--;
        
        if (!k){
            res = root->val;
            return;
        }
        solve(root->right, k, res);
    }
};