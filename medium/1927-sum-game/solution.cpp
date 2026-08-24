/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    bool sumGame(string num) {
        int liczba_pustych_lewa{},suma_lewa{},liczba_pustych_prawa{},suma_prawa{};
        for(int i{};i<num.size()/2;++i) {
            if(num[i] == '?') ++liczba_pustych_lewa;
            else suma_lewa += num[i] - '0';
        }
        for(int i = num.size() / 2;i<num.size();++i) {
            if(num[i] == '?') ++liczba_pustych_prawa;
            else suma_prawa += num[i] - '0';
        }

        const int roznicaZmian = liczba_pustych_prawa - liczba_pustych_lewa;
        const int roznicaSumy = suma_prawa - suma_lewa;

        if(std::abs(roznicaZmian) % 2 != 0 ) return true;

        return 2 * roznicaSumy != -9 * roznicaZmian;
    }
};