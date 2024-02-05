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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Create new node
        TreeNode* node = new TreeNode(val);

        if (!root) {
            return node;
        }

        // Traverse BST
        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        while (curr) {
            prev = curr;
            curr = (node->val > curr->val) ? curr->right : curr->left;
        }

        // Insert
        if (prev->val > node->val) {
            prev->left = node;
        } else {
            prev->right = node;
        }

        return root;
    }
};
