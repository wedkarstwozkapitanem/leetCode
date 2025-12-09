/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums,const long long mod = 5) {
        std::vector<bool> wynik(nums.size(),false);
        long long liczba{};
        for(int i{};i<nums.size();++i) {
            liczba = (liczba * 2 + nums[i]) % mod;
            wynik[i] = (liczba == 0);
        }
        return wynik;
    }
};