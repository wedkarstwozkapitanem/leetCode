/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int wynik{};
        while(n) {
            wynik ^= n;
            n>>=1;
        }
        return wynik;
    }
};