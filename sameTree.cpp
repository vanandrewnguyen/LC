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
    bool doMatch(TreeNode* p, TreeNode* q) {
        // Edge cases for nullptr
        if ((!p && q) || (p && !q)) {
            return false;
        }

        if (!p && !q) {
            return true;
        }

        // Do match
        if (p->val != q->val) {
            return false;
        }

        return ((doMatch(p->left, q->left)) && (doMatch(p->right, q->right)));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base fail
        if ((!p && q) || (p && !q)) {
            return false;
        }

        // Recurse
        return doMatch(p, q);
    }
};
