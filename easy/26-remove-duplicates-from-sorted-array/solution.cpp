/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<set>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::set<int> unikalne;
        for(const auto &i : nums) unikalne.insert(i);

        int licznik{};
        for(const auto &i : unikalne) nums[licznik++] = i;
        

        return licznik;
    }
};