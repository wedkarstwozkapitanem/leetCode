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
public:
    int glebokosc(TreeNode* root) {
        if(!root) return 0;
        int lewe = glebokosc(root -> left);
        if(lewe == -1) return -1;
        int prawe = glebokosc(root -> right);
        if(prawe == -1) return -1;
        if(std::abs(lewe - prawe) > 1) return -1;
        return 1 + std::max(lewe,prawe);
    }
    bool isBalanced(TreeNode* root) {
        return glebokosc(root) != -1;
    }
};