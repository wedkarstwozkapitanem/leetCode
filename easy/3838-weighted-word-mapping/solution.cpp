/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        std::string wynik{};
        for(const auto &slowo : words) {
            int suma{};
            for(const auto &i : slowo) suma += weights[(i - 'a')];
            wynik.push_back(char(25 - (suma % 26) + 'a'));
        }
        return wynik;
    }
};