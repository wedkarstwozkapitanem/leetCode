/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int suma{};
        for(const auto &i : nums) suma = (suma + i) % k;
        return suma;
    }
};