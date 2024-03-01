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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) {
            return false;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        int level = -1;

        while (!q.empty()) {
            level++;
            int count = q.size();

            // Loop through child nodes
            int prev = (level % 2 == 0) ? INT_MIN : INT_MAX;
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (level % 2 == 0) {
                    // even
                    if (node->val <= prev || node->val % 2 == 0) {
                        return false;
                    }
                } else {
                    // odd
                    if (node->val >= prev || node->val % 2 != 0) {
                        return false;
                    }
                }
                prev = node->val;

                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }
        }

        return true;
    }
};
