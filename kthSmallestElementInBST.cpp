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
    void doInOrderTraverse(TreeNode* node, std::vector<int>& vals) {
        if (!node) {
            return;
        }
        doInOrderTraverse(node->left, vals);
        vals.push_back(node->val);
        doInOrderTraverse(node->right, vals);
    }

    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> vals;
        doInOrderTraverse(root, vals);
        return vals[k-1];
    }
};
