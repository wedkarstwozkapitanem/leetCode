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
    bool dfs(TreeNode* lewa_czesc,TreeNode* prawa_czesc) {
        if(lewa_czesc == nullptr && prawa_czesc == nullptr) return true;
        else if(lewa_czesc == nullptr || prawa_czesc == nullptr) return false;
        else if(lewa_czesc -> val != prawa_czesc -> val) return false;
        else  return this->dfs(lewa_czesc->left,prawa_czesc->right) && this->dfs(lewa_czesc->right,prawa_czesc->left);
        
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return this->dfs(root->left,root->right);
    }
};