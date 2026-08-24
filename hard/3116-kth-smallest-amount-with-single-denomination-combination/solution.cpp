/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        std::sort(coins.begin(), coins.end());

        std::vector<int> nowe_monety;

        for (const auto& i : coins) {
            bool podzielny{false};

            for (const auto& p : nowe_monety) {
                if (i % p == 0) {
                    podzielny = true;
                    break;
                }
            }

            if (!podzielny)
                nowe_monety.push_back(i);
        }

        int n = nowe_monety.size();

        std::vector<long long> wielokrotnosc(1 << n);
        wielokrotnosc[0] = 1;

        for (int mask = 1; mask < (1 << n); ++mask) {
            int bit = __builtin_ctz(mask);
            int wczesniejszy = mask & (mask - 1);

            wielokrotnosc[mask] =
                std::lcm(wielokrotnosc[wczesniejszy],static_cast<long long>(nowe_monety[bit]));
        }

        auto liczba = [&](long long x) {
            long long wynik = 0;

            for (int mask = 1; mask < (1 << n); ++mask) {
                long long L = wielokrotnosc[mask];

                if (L > x) continue;

                long long podzielone = x / L;

                if (__builtin_popcount(mask) & 1) wynik += podzielone;
                else wynik -= podzielone;
            }

            return wynik;
        };

        long long lewy = 1;
        long long prawy = 1LL * nowe_monety[0] * k;

        while (lewy < prawy) {
            long long mid = lewy + (prawy - lewy) / 2;

            if (liczba(mid) >= k) prawy = mid;
            else lewy = mid + 1;
        }

        return lewy;
    }
};