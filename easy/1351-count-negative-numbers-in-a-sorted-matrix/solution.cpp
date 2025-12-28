/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int wynik{};
        for(const auto &i : grid) {
            const auto it = std::lower_bound(i.begin(),i.end(),-1,std::greater<int>());
            if(it != i.end()) wynik += i.end() - it;
        }

        return wynik;
    }
};