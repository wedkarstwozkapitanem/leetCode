/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long cyfryniezero{},mnoznik{1},sumacyfr{};

        while(n) {
            const int mod = n % 10;
            if(mod % 10 != 0) {
                cyfryniezero = mod * mnoznik + cyfryniezero;
                mnoznik *= 10;
            }
            sumacyfr += mod;
            n /= 10;
        }

        return cyfryniezero * sumacyfr;
    }
};