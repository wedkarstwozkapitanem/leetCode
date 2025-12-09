/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int smallestNumber(int n) {
        int wynik{};
        while(n) {
            wynik <<= 1;
            ++wynik;
            n /= 2;
        }
        return wynik;
    }
};