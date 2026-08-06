/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min{nums[0]},max{nums[0]};
        for(const auto &i : nums) {
            min = std::min(min,i);
            max = std::max(max,i);
        }
        return std::gcd(min,max);
    }
};