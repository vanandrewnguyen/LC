// theory here: https://www.enjoyalgorithms.com/blog/deletion-in-binary-search-tree

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
    TreeNode* findMinimumNode(TreeNode* root) {
        if (!root) {
            return root;
        }
        if (!root->left) {
            return root;
        }
        return findMinimumNode(root->left);
    }

    TreeNode* doDelete(TreeNode* root, int key) {
        // use the smallest node in subtree
        if (!root) {
            return root;
        }
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key == root->val) {
            if (!root->left) {
                return root->right;
            } else if (!root->right) {
                return root->left;
            } else {
                // if node has no children, it is replaced by non-null child if exists
                // else here min node is found using findMin() and replaces curr node
                // min node is deleted from right subtree
                TreeNode* minVal = findMinimumNode(root->right);
                root->val = minVal->val;
                root->right = deleteNode(root->right, minVal->val);
            }
        }
        
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // recurse since success case has passed
        return doDelete(root, key);
    }
};
