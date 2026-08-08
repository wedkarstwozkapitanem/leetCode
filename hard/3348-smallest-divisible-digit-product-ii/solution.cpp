/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    string dajMinimalnyCiag(const vector<int>& brak) {
        int c2 = brak[0], c3 = brak[1], c5 = brak[2], c7 = brak[3];
        int cnt8 = c2 / 3, r2 = c2 % 3;
        int cnt9 = c3 / 2, r3 = c3 % 2;
        int cnt4 = (r2 == 2) ? 1 : 0;
        int cnt2 = (r2 == 1) ? 1 : 0;
        int cnt3 = (r3 == 1) ? 1 : 0;
        int cnt6 = 0;
        if (cnt2 == 1 && cnt3 == 1) {
            cnt2 = 0; cnt3 = 0; cnt6 = 1;
        } else if (cnt4 == 1 && cnt3 == 1) {
            cnt4 = 0; cnt3 = 0; cnt2 = 1; cnt6 = 1;
        }

        string res = "";
        res.append(cnt2, '2');
        res.append(cnt3, '3');
        res.append(cnt4, '4');
        res.append(c5, '5');
        res.append(cnt6, '6');
        res.append(c7, '7');
        res.append(cnt8, '8');
        res.append(cnt9, '9');
        return res;
    }

    bool mozna(const vector<int>& brak, const int ileMiejsc) {
        string ogon = dajMinimalnyCiag(brak);
        return ogon.size() <= ileMiejsc;
    }

public:
    string smallestNumber(string num, long long t) {
        vector<int> czynniki(4, 0);
        long long k_t = t;
        vector<int> pierwsze = {2, 3, 5, 7};

        for (int i = 0; i < pierwsze.size(); ++i) {
            while (k_t % pierwsze[i] == 0) {
                ++czynniki[i];
                k_t /= pierwsze[i];
            }
        }
        if (k_t != 1) return "-1"; 

        vector<vector<int>> cyfry = {
            {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0},
            {2,0,0,0}, {0,0,1,0}, {1,1,0,0}, {0,0,0,1},
            {3,0,0,0}, {0,2,0,0}
        };

        int n = num.size();
        int pierwszeZero = num.find('0');

        vector<vector<int>> pref(n + 1, vector<int>(4, 0));
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i];
            int d = num[i] - '0';
            if (d != 0) {
                for (int k = 0; k < 4; ++k) pref[i + 1][k] += cyfry[d][k];
            }
        }

        if (pierwszeZero == -1) {
            bool ok = true;
            for (int k = 0; k < 4; ++k) if (pref[n][k] < czynniki[k]) ok = false;
            
            if (ok) return num;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (pierwszeZero != -1 && i > pierwszeZero) continue;

            int aktualnaCyfra = num[i] - '0';
            for (int j = aktualnaCyfra + 1; j <= 9; ++j) {
                vector<int> brak(4, 0);
                for (int k = 0; k < 4; ++k) {
                    brak[k] = max(0, czynniki[k] - pref[i][k] - cyfry[j][k]);
                }

                int ileMiejsc = n - 1 - i;
                if (mozna(brak, ileMiejsc)) {
                    string ogon = dajMinimalnyCiag(brak);
                    string jedynki(ileMiejsc - ogon.size(), '1');
                    return num.substr(0, i) + to_string(j) + jedynki + ogon;
                }
            }
        }

        string ogon = dajMinimalnyCiag(czynniki);
        int docelowaDlugosc = max((int)num.size() + 1, (int)ogon.size());
        string jedynki(docelowaDlugosc - ogon.size(), '1');
        return jedynki + ogon;
    }
};