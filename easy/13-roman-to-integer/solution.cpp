/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<algorithm>
#include<unordered_map>

class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char,int> slownik = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int wynik{},poprzednia{};

        for(int i=s.size()-1;i>=0;--i) {
            int aktualna = slownik[s[i]];
            
            if(aktualna >= poprzednia) wynik += aktualna;
            else wynik -= aktualna;

            poprzednia = aktualna;
        }
        

        return wynik;
    }
};