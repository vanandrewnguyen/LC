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
    void doSearch(TreeNode* node, std::vector<int>& list) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            list.push_back(node->val);
            return;
        }
        doSearch(node->left, list);
        doSearch(node->right, list);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> nodes1;
        doSearch(root1, nodes1);
        std::vector<int> nodes2;
        doSearch(root2, nodes2);
        return (nodes1 == nodes2);
    }
};
