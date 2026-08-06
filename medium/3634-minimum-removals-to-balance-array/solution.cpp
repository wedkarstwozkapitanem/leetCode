/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<iostream>
#include<algorithm>

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());

        long long lewy{};
        long long wynik{};
        for(int i{};i<nums.size();++i) {
            while(nums[i] > (long long)nums[lewy] * k) ++lewy;
            wynik = std::max(wynik,i - lewy + 1);
        }

        return nums.size() - wynik;
    }
};