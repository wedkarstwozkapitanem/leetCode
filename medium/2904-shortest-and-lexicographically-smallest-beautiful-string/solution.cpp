/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/


class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int prawy = static_cast<int>(s.size()) - 1;
        
        while(prawy >= 0 && s[prawy] != '1') --prawy;

        int liczba_jedynek{},lewy{};

        std::string wynik{};
        wynik.reserve(s.size());

        for(int i{};i<=prawy;++i) {

            if(s[i] == '1') ++liczba_jedynek;
            while(lewy < s.size() && liczba_jedynek > k) if(s[lewy++] == '1') --liczba_jedynek;
            while(lewy < s.size() && s[lewy] == '0') ++lewy;

            if(liczba_jedynek == k) {
                if(wynik.empty()) for(int j = lewy; j <= i;++j) wynik.push_back(s[j]);
                else {
                    if(wynik.size() > i - lewy + 1) {
                        wynik = "";
                        for(int j = lewy; j <= i;++j) wynik.push_back(s[j]);
                    } else if(wynik.size() == i - lewy + 1) {
                            std::string tmp{};
                            for(int j = lewy; j <= i;++j) tmp.push_back(s[j]);
                            if(tmp < wynik) wynik = tmp; 
                    }
                }
                 
            }
        }


        return wynik;
    }
};