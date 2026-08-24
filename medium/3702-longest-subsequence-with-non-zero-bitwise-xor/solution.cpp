/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x{};
        bool sameZero{true};
        for(const auto &i : nums) {
            x ^= i;
            if(i != 0) sameZero = false;
        }
        return (x != 0 ? nums.size() : (!sameZero ? nums.size() - 1 : 0));
    }
};