/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) return {{}};
        else if (numRows == 1) return {{1}};

        std::vector<std::vector<int>> trojkot_pascala(numRows);
        trojkot_pascala[0].push_back(1);
        trojkot_pascala[1].push_back(1);
        trojkot_pascala[1].push_back(1);

        for(int i{2};i<numRows;++i) {
            trojkot_pascala[i].push_back(1);
            for(int j{};j<i-1;++j) trojkot_pascala[i].push_back(trojkot_pascala[i-1][j] + trojkot_pascala[i-1][j+1]);
            
            trojkot_pascala[i].push_back(1);
        }
        return trojkot_pascala;
    }
};