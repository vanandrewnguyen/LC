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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Use dfs to recreate tree where if node value is target, don't attach it
        if (root->right) {
            root->right = removeLeafNodes(root->right, target);
        }
        
        if (root->left) {
            root->left = removeLeafNodes(root->left, target);
        }
        
        if (!root->left && !root->right && root->val == target) {
            return NULL;
        }

        return root;
    }
};
