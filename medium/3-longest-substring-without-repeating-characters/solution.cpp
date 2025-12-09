/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int wynik{},aktualny{};
        std::set<char> litery;
        for(size_t i{};i<s.size();++i){
            if(litery.find(s[i]) == litery.end()) {
                litery.insert(s[i]);
                ++aktualny;
            } else {
                while(s[i - aktualny] != s[i]) litery.erase(s[i - aktualny--]);
            }

            if(aktualny > wynik) wynik = aktualny;
        }
        return wynik;
    }
};