/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<vector>

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        std::vector<std::vector<int>> mat(n,std::vector<int>(n,0));
        for(const auto q : queries) {
            int row1 = q[0],col1 = q[1],row2 = q[2],col2 = q[3];
            ++mat[row1][col1];
            if(col2+1 < n) --mat[row1][col2+1];
            if(row2 + 1 < n) --mat[row2 + 1][col1];
            
            if (row2 + 1 < n && col2 + 1 < n) mat[row2 + 1][col2 + 1]++;
            //for(int i = q[0];i<=q[2];++i) for(int j = q[1];j<=q[3];++j) ++mat[i][j];
        }

        for(int i{};i<n;++i) {
            for(int j{};j<n;++j) {
                if(i) mat[i][j] += mat[i - 1][j];
                if(j) mat[i][j] += mat[i][j-1];
                if(i && j) mat[i][j] -= mat[i-1][j-1];
            }
        }
        return mat;
    }
};