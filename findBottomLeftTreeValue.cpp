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
    int findBottomLeftValue(TreeNode* root) {
        if (!root) {
            return 0;
        }

        // level order traversal, but then we return the left most index of the LAST level
        std::vector<std::vector<int>> levelValues;
        std::queue<TreeNode*> q;
        q.push(root);

        std::vector<int> baseLevel;
        baseLevel.push_back(root->val);
        levelValues.push_back(baseLevel);

        while(!q.empty()) {
            std::vector<int> currLevel;
            int count = q.size();

            // Loop through child nodes
            for (int i = 0; i < count; i++) {
                TreeNode* curr = q.front();
                q.pop();
    
                // add to queue
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                currLevel.push_back(curr->val);
            }
            levelValues.push_back(currLevel);
        }

        int layers = levelValues.size()-1;
        return levelValues[layers][0];
    }
};


/*
smart solution
class Solution {
public:
    int ans=0, level=-1;
    void dfs(TreeNode* node, int h){
        if (!node) return;

        if (h>level){
            ans=node->val;
            level=h;
        } 
        dfs(node->left, h+1);// Recursion uses system stack FILO
        dfs(node->right, h+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};

*/

