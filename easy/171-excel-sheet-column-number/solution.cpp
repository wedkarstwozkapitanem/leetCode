/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int wynik{};
        for(int i{};i<columnTitle.size();++i) {
            wynik = wynik * 26 + (columnTitle[i] - 'A' + 1);
        }
        return wynik;
    }
};