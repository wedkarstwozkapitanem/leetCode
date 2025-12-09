/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<algorithm>
#include<unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> liczby;
        int licznik{};
        for(const auto &i : nums) {
            const auto result = liczby.find(target - i);
            if(result != liczby.end() && (i + result -> first ) == target){
                return {result -> second,licznik};
            }
            liczby[i] = licznik++;
        }
        return {-1,-1};
    }
};