/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<unordered_map>
#include<vector>

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int wynik{};

        std::vector<int> odw(26,-1),odwk(26,-1);

        for(int i{};i<s.size();++i) {
            if(odw[s[i]-'a'] == -1) odw[s[i]-'a'] = i;
            odwk[s[i]-'a'] = i;
        }
        for(int i{};i<26;++i) {
            int poczotek = odw[i],koniec=odwk[i];
            if(poczotek == -1 || poczotek == koniec) continue;

            const char litera = i + 'a';
            std::unordered_set<char> unikalne_wartosci;
            for(int i = poczotek+1;i<koniec;++i) unikalne_wartosci.insert(s[i]);
            wynik += unikalne_wartosci.size();
        }
        return wynik;
    }
};