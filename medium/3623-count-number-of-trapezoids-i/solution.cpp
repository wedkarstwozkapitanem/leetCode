/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<algorithm>
#include<unordered_map>

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int wynik{};
        const long long MOD = 1e9 + 7;
        std::unordered_map<int,int>  krawedzie;

        for(const auto &i : points) krawedzie[i[1]]++;
        
        int suma{};
        for(const auto &[klucz,wartosc] : krawedzie) {
            if(wartosc < 2) continue;
            long long krawedz = wartosc % MOD * (wartosc - 1) % MOD / 2;
            wynik = (wynik + krawedz * suma) % MOD;
            suma = (suma + krawedz) % MOD;
        }
        
        return wynik % MOD;
    }
};