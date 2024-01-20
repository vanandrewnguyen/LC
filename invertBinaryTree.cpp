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
    void doInvert(TreeNode* root) {
        if (root) {
            doInvert(root->left);
            doInvert(root->right);

            struct TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = tmp;
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        doInvert(root);
        return root;
    }
};
