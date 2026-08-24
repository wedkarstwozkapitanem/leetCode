/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        const int n = stones.size();
        std::vector<int> prefiks_sum(n+1);
        prefiks_sum[0] = stones[0];
        for(int i{1};i<stones.size();++i) prefiks_sum[i] = prefiks_sum[i-1] + stones[i];

        int wynik = prefiks_sum[n-1];
        for(int i = n - 2; i>=1;--i) wynik = std::max(wynik,prefiks_sum[i] - wynik);
        
        return wynik;
    }
};