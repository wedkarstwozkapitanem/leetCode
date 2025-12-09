/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<algorithm>
#include<limits.h>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto licznik{nums.size()};
        for(auto &i : nums) {
            if(i==val) {
                i = INT_MAX;
                --licznik;
            }
        }
        std::sort(nums.begin(),nums.end());
        return licznik;
    }
};