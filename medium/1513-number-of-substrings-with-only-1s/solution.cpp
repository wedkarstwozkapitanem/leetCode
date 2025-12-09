/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int numSub(string s) {
        constexpr long long MOD = 1e9 + 7;
        long long wynik{},licznik{};

        for(const auto &i : s) {
            if(i=='1') ++licznik;
            else {
                wynik += ((licznik * (licznik + 1)) / 2) % MOD;
                licznik = 0;
            }
        }
        wynik += ((licznik * (licznik + 1)) / 2) % MOD;

        return wynik % MOD;
    }
};