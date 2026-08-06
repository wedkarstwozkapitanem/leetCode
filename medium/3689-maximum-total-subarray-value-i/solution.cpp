/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int min{INT_MAX},max{INT_MIN};
        for(const auto &i : nums) {
            min = std::min(min,i);
            max = std::max(max,i);
        }

        return (long long)((long long)k * (long long)(max - min));
    }
};