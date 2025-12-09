/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<set>

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        std::set<long long> liczby;

        for(const auto &i : nums) {
            liczby.insert(i);
            if(original == i) original *= 2;
        }

        bool znaleziono{false};
        do {
            znaleziono = false;
            auto it = liczby.find(original);
            if(it != liczby.end()){
               original <<= 1;
               znaleziono = true;
            }
        } while(znaleziono);
        return original;
    }
};