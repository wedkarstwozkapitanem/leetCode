/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int MAX = *max_element(nums.begin(), nums.end());
        std::vector<long long> liczba_par(MAX+1,0);

        for(const auto &i : nums) ++liczba_par[i];
        std::vector<long long> podzielne(MAX+1,0);
        for(int i{1};i<=MAX;++i) {
            for(int j{i};j<=MAX;j+=i) podzielne[i] += liczba_par[j];
        }
        vector<long long> gcdCount(MAX + 1, 0);

        for(int d = MAX; d >= 1; d--) {
            gcdCount[d] = podzielne[d] * (podzielne[d] - 1) / 2;
            for(int k = d + d; k <= MAX; k += d)  gcdCount[d] -= gcdCount[k];   
        }
 
        std::vector<long long> pref(MAX + 1, 0);

        for(int i = 1; i <= MAX; i++) pref[i] = pref[i-1] + gcdCount[i];

        std::vector<int> wynik(queries.size());

        for(int i = 0; i < queries.size(); i++) wynik[i] = lower_bound(pref.begin(), pref.end(), queries[i] + 1) - pref.begin();

        return wynik;
    }
};