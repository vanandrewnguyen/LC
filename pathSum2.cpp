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
    void solve(TreeNode* root, int targetSum, std::vector<std::vector<int>> &res, std::vector<int> temp, int sum) {
        if (!root) {
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if (!root->left && !root->right) {
            // leaf node
            if (sum == targetSum) {
                res.push_back(temp);
            } else {
                return;
            }
        }
        // dfs down l and r
        solve(root->left, targetSum, res, temp, sum);
        solve(root->right, targetSum, res, temp, sum);
    } 

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> res;
        std::vector<int> temp; // temp path
        int sum = 0;
        solve(root, targetSum, res, temp, sum);
        return res;
    }
};
