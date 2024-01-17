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
    int doDFS(TreeNode* root, int depth) {
        if (!root) {
            return depth;
        }

        int left = (root->left) ? doDFS(root->left, depth+1) : depth;
        int right = (root->right) ? doDFS(root->right, depth+1) : depth;
        return (left > right) ? left : right;
    }

    int maxDepth(TreeNode* root) {
        int depth = 0;
    
        if (!root) {
            return 0;
        }
    
        return doDFS(root, depth+1);
    }
};
