/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int minimumPushes(string word) {
        int wynik{},koszt{1};
        for(int i{1};i<=word.size();++i) {
            wynik += koszt;
            if(i % 8 == 0) ++koszt;
        }
        return wynik;
    }
};