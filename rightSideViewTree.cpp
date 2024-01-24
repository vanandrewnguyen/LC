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
    vector<int> rightSideView(TreeNode* root) {
        // do level order traversal, then get all the rightmost items (see LC 102.)
        std::vector<std::vector<int>> levelOrderGroups;
        std::vector<int> res;
        if (!root) { return res; }
        
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

        for (int i = 0; i < levelOrderGroups.size(); i++) {
            int len = levelOrderGroups[i].size();
            res.push_back(levelOrderGroups[i][len-1]);
        }
        return res;
    }
};
