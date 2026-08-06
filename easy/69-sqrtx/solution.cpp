/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int mySqrt(int x) {
        if(!x || x == 1) return x;
        int lewy{},prawy{((x < 2) ? x : x/2 + 1)},srodek{};

        while(lewy <= prawy) {
            srodek = (lewy + prawy) / 2;
            if(srodek <= x / srodek) lewy = srodek + 1;
            else prawy = srodek - 1;
        }

        return lewy - 1;
    }
};