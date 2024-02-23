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
    int doDFS(TreeNode* root, int& diameter) {
        if (!root) {
            return -1;
        }
        int left = doDFS(root->left, diameter);
        int right = doDFS(root->right, diameter);
        diameter = std::max(diameter, left + right + 2); // + 2 edges for left to root to right
        return std::max(left, right) + 1; // diameter is unaffected by this

    }

    int diameterOfBinaryTree(TreeNode* root) {
        // length of longest path between two nodes in a tree
        int diameter = 0;
        doDFS(root, diameter);
        return diameter;
    }
};
