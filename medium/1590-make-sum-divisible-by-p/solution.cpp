/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<limits>

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const size_t n = nums.size();
        //std::vector<long long> prefix(n+1,0);
        //for(int i{1};i<=n;++i) prefix[i] = (prefix[i-1] + nums[i-1]) % p;
        //const long long suma = prefix[n];
        
        //if(!(suma % p)) return 0;

        long long suma{};
        for(const auto &i : nums) suma += i;
        int poszukiwana = suma % p;
        if(poszukiwana == 0) return 0;

        std::unordered_map<int, int> prefiks;
        prefiks[0] = -1;

        int sumpref{};
        int wynik = n;
        for(int i{};i<n;++i) {
            sumpref = (sumpref + nums[i]) % p;

            const auto it = prefiks.find((sumpref - poszukiwana + p) % p);
            if (it != prefiks.end()) wynik = std::min(wynik, (i - it -> second) );

            prefiks[sumpref] = i;
        }


        return wynik == n ? -1 : wynik;
    }
};