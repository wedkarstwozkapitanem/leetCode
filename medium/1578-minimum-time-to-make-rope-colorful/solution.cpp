/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int wynik{};
        for(size_t i{};i<colors.size()-1;++i) {
            if(colors[i] == colors[i+1]) {
                wynik += std::min(neededTime[i],neededTime[i+1]);
                neededTime[i + 1] = std::max(neededTime[i],neededTime[i+1]);
            }
        }
        return wynik;
    }
};