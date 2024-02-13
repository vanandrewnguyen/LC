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
    int maxLevelSum(TreeNode* root) {
        // do level order traversal
        std::vector<std::vector<int>> levelOrderGroups;
        std::vector<int> res;
        if (!root) { return 0; }
        
        std::queue<TreeNode*> q;
        q.push(root);

        // BFS
        while (!q.empty()) {
            int count = q.size();
            vector<int> curr;

            // Loop through child nodes
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                curr.push_back(node->val);

                // Put children in list
                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }

            levelOrderGroups.push_back(curr);
        }

        int highest = INT_MIN;
        int level = 0;
        for (int i = 0; i < levelOrderGroups.size(); i++) {
            int sum = std::accumulate(levelOrderGroups[i].begin(), levelOrderGroups[i].end(), 0);
            if (sum > highest) {
                highest = sum;
                level = i+1;
            }
        }
        return level;
    }
};
