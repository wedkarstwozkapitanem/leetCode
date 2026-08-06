/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int minimumPushes(string word) {
        std::vector<std::pair<int,short>> czestotliwosc(26);
        for(const auto &i : word)  {
            ++czestotliwosc[i - 'a'].first;
            czestotliwosc[i - 'a'].second = short(i - 'a');
        }

        std::sort(czestotliwosc.begin(),czestotliwosc.end(),std::greater<std::pair<int,short>>());

        int wynik{};
        for(int i{};i<26;++i) wynik += ((i / 8) + 1) * czestotliwosc[i].first;
        
        return wynik;
    }
};