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
    bool dfs(const TreeNode* root,const int targetSum,int aktualna=0) {
        if(!root) return false;
        aktualna += root -> val;
        if(root -> left ==  nullptr && root -> right ==  nullptr ) return aktualna == targetSum;
        return this->dfs(root -> left,targetSum,aktualna) || dfs(root -> right,targetSum,aktualna);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return this->dfs(root,targetSum,0);
    }
};