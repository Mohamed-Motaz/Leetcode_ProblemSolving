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

    int getLen(TreeNode* root){
        if (!root) return 0;
        
        int left = getLen(root->left);
        int right = getLen(root->right);
        
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
       if (!root) return 1;
        
        int lenLeft = getLen(root->left);
        int lenRight = getLen(root->right);
        
        if (abs(lenLeft - lenRight) > 1)
            return 0;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};