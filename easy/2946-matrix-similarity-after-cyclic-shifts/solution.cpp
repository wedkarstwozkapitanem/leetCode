/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        const int n = mat[0].size();
        k %= n;
        for(int i{};i<mat.size();++i) {
            for(int j{};j<n;++j) {
                int przesuniecie{};
                if(j % 2 == 0) przesuniecie = (j - k + n) % n;
                else  przesuniecie = (j + k) % n;
                if(mat[i][j] != mat[i][przesuniecie]) return false;
            }
        }
        return true;
    }
};