/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include <vector>
#include <set>
#include <unordered_map>

class Solution {
private:
    struct licz {
        long long wyst{}, liczba{};
        bool operator<(const licz& inna) const {
            if (wyst == inna.wyst) return liczba > inna.liczba;
            return wyst > inna.wyst;
        }
    };

public:
    std::vector<long long> findXSum(std::vector<int>& nums, int k, int x) {
        std::unordered_map<int, long long> wyst;
        std::multiset<licz> topx, reszta;
        std::vector<long long> wynik;
        long long suma = 0;

        auto dodaj = [&](int a) {
            long long f = ++wyst[a];
            licz nowa{f, a};

            if (f > 1) {
                licz stara{f - 1, a};
                if (auto it = topx.find(stara); it != topx.end()) {
                    suma -= it->wyst * it->liczba;
                    topx.erase(it);
                } else if (auto it = reszta.find(stara); it != reszta.end())  reszta.erase(it);
                
            }

            if ((int)topx.size() < x) {
                topx.insert(nowa);
                suma += nowa.wyst * nowa.liczba;
            } else {
                auto it = std::prev(topx.end());
                if (nowa < *it) {
                    reszta.insert(*it);
                    suma -= it->wyst * it->liczba;
                    topx.erase(it);
                    topx.insert(nowa);
                    suma += nowa.wyst * nowa.liczba;
                } else  reszta.insert(nowa);
            }
        };

        auto usun = [&](int a) {
            long long f = wyst[a]--;
            if (f == 0) {
                wyst.erase(a);
                return;
            }
            licz obecna{f, a}, nowa{f - 1, a};

            if (auto it = topx.find(obecna); it != topx.end()) {
                suma -= it->wyst * it->liczba;
                topx.erase(it);
                if (nowa.wyst > 0) reszta.insert(nowa);
            } else if (auto it = reszta.find(obecna); it != reszta.end()) {
                reszta.erase(it);
                if (nowa.wyst > 0) reszta.insert(nowa);
            }

            if ((int)topx.size() < x && !reszta.empty()) {
                auto najlepsza = *reszta.begin();
                reszta.erase(reszta.begin());
                topx.insert(najlepsza);
                suma += najlepsza.wyst * najlepsza.liczba;
            }

            if (wyst[a] == 0) wyst.erase(a);
        };

        for (int i = 0; i < k; ++i) dodaj(nums[i]);
        wynik.push_back(suma);

        for (int i = k; i < (int)nums.size(); ++i) {
            usun(nums[i - k]);
            dodaj(nums[i]);
            wynik.push_back(suma);
        }

        return wynik;
    }
};
