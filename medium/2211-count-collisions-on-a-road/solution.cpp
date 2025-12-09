/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int countCollisions(string directions) {
        int i{},j = directions.size() - 1;
        while(i < directions.size()  && directions[i] == 'L') ++i;
        while(j >= 0 && directions[j] == 'R') --j;
        int wynik{};

        for(;i<=j;++i) {
            if(directions[i] != 'S') ++wynik;
        }
        return wynik;
    }
};