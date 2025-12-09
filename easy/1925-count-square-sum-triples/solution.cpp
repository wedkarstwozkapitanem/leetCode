/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int countTriples(int n) {
        int wynik{};
        for(int a{1};a<=n;++a) {
            for(int b=1;b<=n;++b) {
                int c2 = a*a+b*b;
                int c = std::sqrt(c2);
                if(c <=n && c * c == c2) ++wynik;
            }
        }
        return wynik;
    }
};