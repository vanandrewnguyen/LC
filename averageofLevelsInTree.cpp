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
    vector<double> averageOfLevels(TreeNode* root) {
        // Do BFS and track average for each layer
        std::vector<double> average;
        std::queue<TreeNode*> queue;
        queue.push(root);
        queue.push(nullptr);
        // Nullptr push lets us know to cut off per level

        TreeNode* curr;
        double sum = 0;
        double n = 0;

        // Traverse
        while (!queue.empty()) {
            curr = queue.front();
            queue.pop();

            // Two cases, one to add an average, other to sum
            if (!curr) {
                // End and get sum of current level
                average.push_back(sum / n);
                sum = 0;
                n = 0;
                if (!queue.empty()) { queue.push(nullptr); }
            } else {
                sum += curr->val;
                n++;
                if (curr->left) { queue.push(curr->left); }
                if (curr->right) { queue.push(curr->right); }
            }
        }

        return average;
    }
};
