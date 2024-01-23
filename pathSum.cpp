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
    void doDFS(std::vector<int>& sums, TreeNode* node, int sum) {
        if (!node) {
            return;
        }

        sum += node->val;

        if (!node->left && !node->right) {
            sums.push_back(sum);
            return;
        }

        doDFS(sums, node->left, sum);
        doDFS(sums, node->right, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        std::vector<int> sums;
        doDFS(sums, root, 0);

        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] == targetSum) {
                return true;
            }
        }
        return false;
    }
};
