/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();

        std::vector<int> liczba_kamieni_od_konca(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) liczba_kamieni_od_konca[i] = liczba_kamieni_od_konca[i + 1] + piles[i];
        

        std::vector<std::vector<int>> maks_kamieni(n + 1,vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int m = n; m >= 1; --m) {

                if (i + 2 * m >= n) {
                    maks_kamieni[i][m] = liczba_kamieni_od_konca[i];
                    continue;
                }

                int najlepszy = 0;

                for (int x = 1; x <= 2 * m; ++x) {
                    if (i + x > n) break;

                    int new_m = max(m, x);

                    int aktualny = liczba_kamieni_od_konca[i] - maks_kamieni[i + x][new_m];

                    najlepszy = max(najlepszy, aktualny);
                }

                maks_kamieni[i][m] = najlepszy;
            }
        }

        return maks_kamieni[0][1];
    }
};