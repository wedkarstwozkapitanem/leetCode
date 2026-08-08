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
    int dfs(TreeNode* root,int glebokosc=0) {
        if(root == nullptr) return glebokosc;
        return std::max(dfs(root->left,glebokosc + 1),dfs(root->right,glebokosc + 1));  
    }
public:
    int maxDepth(TreeNode* root) {
        return this->dfs(root);
    }
};