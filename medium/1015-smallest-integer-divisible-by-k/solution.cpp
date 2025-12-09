/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unsigned long long liczba{1};
        int licznik{1};
        if(!(k%2) || !(k%5)) return -1;
        
        while(liczba % k != 0) {
            liczba = ((liczba * 10) + 1) % k;
            ++licznik;
            if(liczba == ((liczba * 10) + 1) % k) return -1;
        }
        return licznik;
    }
};