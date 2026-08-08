/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

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
private:
    int dfs(TreeNode* root) {
        if(root == nullptr) return INT_MAX;
        if(root -> left == nullptr && root->right == nullptr) return 1;

        return 1 + std::min(dfs(root->left),dfs(root->right));
    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return this->dfs(root);
    }
};