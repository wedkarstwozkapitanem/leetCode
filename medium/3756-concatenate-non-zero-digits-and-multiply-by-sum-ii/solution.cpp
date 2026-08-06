/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        std::vector<long long> prefiksy(s.size()+1),wartosc(s.size() + 1),pow10(s.size() + 1,1),liczbacyfr(s.size() + 1);

        long long liczba{};
        for(int i{1};i<s.size()+1;++i) {
            prefiksy[i] = (prefiksy[i-1] + int(s[i-1] - '0')) % MOD;
            liczbacyfr[i] = liczbacyfr[i-1];
            if(s[i-1] != '0') {
                liczba = (liczba * 10 + int(s[i-1] - '0')) % MOD;
                ++liczbacyfr[i];
            }
            wartosc[i] = (liczba);
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        std::vector<int> wynik(queries.size());

        for(int i{};i<queries.size();++i) {
            const auto a = queries[i][0];
            const auto b = queries[i][1] + 1;

            const auto suma = (prefiksy[b] - prefiksy[a] + MOD) % MOD;

            auto a_p = wartosc[a];
            auto b_p = wartosc[b];

            const auto ileLiczb = liczbacyfr[b] - liczbacyfr[a];
            
            long long liczba = (wartosc[b] - (wartosc[a] * pow10[ileLiczb]) % MOD + MOD) % MOD;

            wynik[i] = (liczba * suma + MOD) % MOD;
        }      

        return wynik;
    }
};