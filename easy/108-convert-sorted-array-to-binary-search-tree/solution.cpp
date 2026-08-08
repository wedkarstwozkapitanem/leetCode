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
    TreeNode* dfs(const vector<int>& nums,int lewy,int prawy) {
        if(lewy > prawy) return nullptr;
        int srodek = (lewy + prawy) / 2;
        TreeNode* drzewo = new TreeNode(nums[srodek]);
        drzewo -> left = dfs(nums,lewy,srodek - 1);
        drzewo -> right = dfs(nums,srodek + 1,prawy);
        return drzewo;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0, nums.size() - 1);
    }
};