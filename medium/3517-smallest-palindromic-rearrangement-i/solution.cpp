/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    string smallestPalindrome(const string &s) {
        if(s.size() == 1) return s;
        
        int liczba_wystopien[26]{};
        for(const auto &i : s) ++liczba_wystopien[i - 'a'];

        const int n = s.size();
        int idx{};
        std::string wynik(s.size(),' ');

        for(int i{};i<26;++i) {
            int ile_liter = liczba_wystopien[i] ;
            const char aktualna_litera =  char(i + 'a');
            while(ile_liter > 1) {
                wynik[idx] = aktualna_litera;
                wynik[n - idx - 1] =  aktualna_litera;
                ++idx;
                ile_liter -= 2;
            }
            if(ile_liter == 1) wynik[n/2] = aktualna_litera;
        }
        
        return wynik;
    }
};