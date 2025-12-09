/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include <vector>
#include <string>

class Solution {
public:
    int numberOfSubstrings(std::string s) {
        constexpr int LIMIT = 201;

        int n = s.size();

        std::vector<int> prefiks(n + 1, 0);
        std::vector<int> pozycje_zer;

        long long wynik = 0;


        int runOne = 0;
        for (int i = 1; i <= n; ++i) {
            prefiks[i] = prefiks[i - 1];
            if (s[i - 1] == '1') {
                ++prefiks[i];
                ++runOne;
            } else {
                if (runOne > 0) {
                    wynik += (long long)runOne * (runOne + 1) / 2;
                    runOne = 0;
                }
                pozycje_zer.push_back(i - 1);
            }
        }

        if (runOne > 0) {
            wynik += (long long)runOne * (runOne + 1) / 2;
        }

        int Z = pozycje_zer.size();

        for (int z = 1; z <= LIMIT; z++) {
            if (z > Z)
                break;

            for (int i = 0; i + z - 1 < Z; i++) {

                int lewe = pozycje_zer[i];
                int prawe = pozycje_zer[i + z - 1];

                int L = (i == 0 ? 0 : pozycje_zer[i - 1] + 1);
                int R = (i + z == Z ? n - 1 : pozycje_zer[i + z] - 1);

                int potrzebne = z * z;


                for (int l = lewe; l >= L; --l) {

                    int lo = prawe, hi = R, ok = -1;

                    while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        int ones = prefiks[mid + 1] - prefiks[l];

                        if (ones >= potrzebne) {
                            ok = mid;
                            hi = mid - 1;
                        } else {
                            lo = mid + 1;
                        }
                    }

                    if (ok == -1)
                        continue;     

                    wynik += (R - ok + 1);
                }
            }
        }

        return (int)wynik;
    }
};
