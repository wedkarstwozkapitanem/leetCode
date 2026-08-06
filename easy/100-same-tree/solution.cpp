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
    bool idz_po_drzewach(TreeNode* p, TreeNode* q) {

        if(p == nullptr && q == nullptr) return true;
        else if(p == nullptr || q == nullptr) return false;
        else if( p->val != q->val) return false;

        else {
            bool a = this -> idz_po_drzewach(p->left, q->left);
            bool b =  this -> idz_po_drzewach(p->right, q->right);
            if(!a || !b) return false;
            else return true;
        }
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return this->idz_po_drzewach(p, q);
    }
};