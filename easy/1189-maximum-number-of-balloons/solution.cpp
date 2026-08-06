/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int maxNumberOfBalloons(string text,const std::string &szukany = "balloon") {
        if (text.empty()) return 0;
        std::unordered_map<char,int> liczba_wystopien;
        for(const auto &i : text) ++liczba_wystopien[i];
        
        int wynik{INT_MAX};
        for(const auto &i :  szukany) {
            wynik = std::min(wynik, liczba_wystopien[i]);
            liczba_wystopien[i] /= 2;
        }
        return wynik;
    }
};