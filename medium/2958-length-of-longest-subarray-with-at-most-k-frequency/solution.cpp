/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return 1;

        std::unordered_map<int,int> czestotliwosc;

        int lewy{},liczba_elementow{};
        for(int p{};p<nums.size();++p) {
            const auto i = nums[p];
            ++czestotliwosc[i];
            while(czestotliwosc[i] > k) {
                --czestotliwosc[nums[lewy]];
                ++lewy;
            }
            liczba_elementow = std::max(liczba_elementow,p - lewy + 1);
        }
        return liczba_elementow;
    }
};