/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        std::vector<std::pair<bool,int>> liczbablokow;
        s = '1' + s + '1';

        int liczbajedynek{-2};
        for(const auto &i : s) {
            if(liczbablokow.empty() || liczbablokow.back().first != bool(int(i - '0'))) liczbablokow.emplace_back(bool(int(i - '0')),1);
            else ++liczbablokow.back().second;
            if(i=='1') ++liczbajedynek;
        }

        int wynik{};

        for(int i{1};i<liczbablokow.size() - 1;++i) {
            if(liczbablokow[i].first && !liczbablokow[i-1].first && !liczbablokow[i + 1].first) wynik = std::max(wynik, liczbablokow[i-1].second + liczbablokow[i + 1].second);
        }
        return wynik + liczbajedynek; 
    }
};