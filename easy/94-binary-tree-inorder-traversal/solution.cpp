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
    void dfs(TreeNode* root,std::vector<int> &odwiedzone) {
        if(root != nullptr) {
            dfs(root -> left,odwiedzone);
            odwiedzone.push_back(root -> val);
            dfs(root -> right,odwiedzone);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> wynik;
        dfs(root,wynik);
        return wynik;
    }
};