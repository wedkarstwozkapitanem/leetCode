/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x{0};
        for(const auto &i : nums) x ^= i;
        return x;
    }
};