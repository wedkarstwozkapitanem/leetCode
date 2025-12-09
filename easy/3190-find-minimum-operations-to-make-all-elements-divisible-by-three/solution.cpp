/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int wynik{};
        for(const auto &i : nums) {
            if(!(i%3)) continue;
            ++wynik;
        }
        return wynik;
    }
};