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
class FindElements {
public:
    std::set<int> mySet;

    FindElements(TreeNode* root) {
        root->val = 0;
        fillTree(root);
    }

    void fillTree(TreeNode* node) {
        if (!node) {
            return;
        }

        mySet.insert(node->val);
        if (node->left) {
            node->left->val = 2 * node->val + 1;
            fillTree(node->left);
        }
        if (node->right) {
            node->right->val = 2 * node->val + 2;
            fillTree(node->right);
        }
    }
    
    bool find(int target) {
        return (mySet.find(target) != mySet.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
