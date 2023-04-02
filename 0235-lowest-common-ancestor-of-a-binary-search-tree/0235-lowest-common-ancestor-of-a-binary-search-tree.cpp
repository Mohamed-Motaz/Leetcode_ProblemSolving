/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val >= q->val)
            swap(p, q);
        if (p->val <= root->val && root->val <= q->val)
            return root;
        
        //handle cases of root
        if (root->val == p->val && root->right && root->right->val == q->val)
            return root;
        if (root->val == q->val && root->right && root->right->val == p->val)
            return root;
        if (root->val == p->val && root->left && root->left->val == q->val)
            return root;
        if (root->val == q->val && root->left && root->left->val == p->val)
            return root;
        
        if (p->val <= root->val && q->val <= root->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};