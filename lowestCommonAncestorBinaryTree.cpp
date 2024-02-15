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
        // Fail case
        if (!root) {
            return nullptr;
        }

        // Found root
        if (root->val == p->val || root->val == q->val) {
            // This is only the case where we have a lca being one of the nodes
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
                // p or q on left then recurse left
                return left;
            } else {
                // ditto, right
                return right;
            }
        }
    }
};
