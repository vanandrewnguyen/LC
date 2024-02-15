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
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }

        /*
        Basic solution that works for binary tree (and also BST, but slower)
        if (!root) {
            return nullptr;
        }

        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (!left && !right) {
            // No children = can't be lca
            return nullptr;
        } else {
            if (left && right) {
                // If p or q is on left AND right then node is lca
                return root;
            } else if (left) {
                return left;
            } else {
                return right;
            }
        }
        */
    }
};
