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
    void doDFS(TreeNode* node, std::vector<int>& sums, int sum) {
        if (!node) {
            return;
        }

        // No need to string conversion
        sum = sum * 10 + node->val;

        if (!node->left && !node->right) {
            // End of branch
            sums.push_back(sum);
        }

        // Else, recurse
        doDFS(node->left, sums, sum);
        doDFS(node->right, sums, sum);
    }

    int sumNumbers(TreeNode* root) {
        std::vector<int> sums;
        
        // DFS to add each branch as a sum
        doDFS(root, sums, 0);

        // Then sum all branch sums
        int res = 0;
        for (int sum : sums) {
            res += sum;
        }
        return res;
    }
};
