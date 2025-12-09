/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x== 0) return true;

        std::string liczba = std::to_string(x);
        size_t rozmiar = liczba.size();
        if(rozmiar==2) return liczba[0] == liczba[1];

        for(size_t i{};i<rozmiar/2;++i) {
            if(liczba[i] != liczba[rozmiar-i-1]) return false;
        }
        return true;
    }
};