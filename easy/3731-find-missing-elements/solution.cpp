/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int ostatni = nums[0];
        std::vector<int> wynik;
        for(const auto &i : nums) {
            for(int j=ostatni + 1;j<i;++j) wynik.push_back(j);
            ostatni = i;
        }
        return wynik;
    }
};