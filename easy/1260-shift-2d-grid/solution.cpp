/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(grid.empty()) return {};
        if(grid[0].size() == 1 && grid.size() == 1) return grid;
        std::vector<std::vector<int>>  wynik(grid.size(),std::vector<int>(grid[0].size()));
       while(k--) {
        for(int i{};i < grid.size();++i) {
            for(int j{}; j < grid[0].size();++j) {
               const int ak = grid[i][j];
               if(i==grid.size()-1 && j == grid[0].size() - 1) wynik[0][0] = ak;
               else if(j == grid[i].size() - 1) wynik[i + 1][0] = ak;
               else wynik[i][j+1] = ak;
            }
            }
            grid = wynik;
        } 
        return wynik;
    }
};