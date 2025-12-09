/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<set>

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        std::set<int> miasto;
        std::vector<int> wynik;
        for(const auto &i : nums) {
            if(miasto.find(i) != miasto.end()) wynik.push_back(i);
            miasto.insert(i);
        }        
        return wynik;
    }
};