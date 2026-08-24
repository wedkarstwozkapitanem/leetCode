/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/
class Solution {
public:
    bool checkDivisibility(const int &n) {
        int suma_cyfr{},iloczyn_cyfr{1}, p = n;
        while(p) {
            const int ostatnia_cyfra = p % 10;
            suma_cyfr += ostatnia_cyfra;
            iloczyn_cyfr *= ostatnia_cyfra;
            p /= 10;
        }
        return ((n % (suma_cyfr + iloczyn_cyfr)) == 0);
    }
};