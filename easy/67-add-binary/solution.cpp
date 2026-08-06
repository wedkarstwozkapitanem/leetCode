/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if(b.size() > a.size()) return addBinary(b,a);
        
        const int rozmiar_a = a.size(), rozmiar_b = b.size();
        std::string wynik{};
        bool przeniesienie{0};
        bool a_b{},b_b{};

        int i_a = a.size() - 1, i_b = b.size() - 1;
        while(i_a >= 0 && i_b >= 0) {
            if(i_a >= 0) a_b = bool(a[i_a] - '0');
            if(i_b >= 0) b_b = bool(b[i_b] - '0');
            const int dodaj = int(a_b) + int(b_b) + int(przeniesienie);
            przeniesienie = (dodaj >= 2);
            wynik.push_back((dodaj == 1 || dodaj == 3 ? '1' : '0'));
            --i_a;
            --i_b;
        }
 
        while(i_a >= 0) {
            a_b = bool(a[i_a] - '0');
            const int dodaj = int(a_b) + int(przeniesienie);
            przeniesienie = (dodaj >= 2);
            wynik.push_back((dodaj == 1 || dodaj == 3 ? '1' : '0'));
            --i_a;
        }
        while(i_b >= 0) {
            b_b = bool(a[i_b] - '0');
            const int dodaj = int(b_b) + int(przeniesienie);
            przeniesienie = (dodaj >= 2);
            wynik.push_back((dodaj == 1 || dodaj == 3 ? '1' : '0'));
            --i_b;
        }
        
        if(przeniesienie) wynik.push_back('1');
        std::reverse(wynik.begin(),wynik.end());
        return wynik;
    } 
};