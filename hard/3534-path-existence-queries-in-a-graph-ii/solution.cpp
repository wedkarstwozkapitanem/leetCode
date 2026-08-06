/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include <algorithm>
#include <vector>

class Solution {
private:
    inline int policz_liczbe_skokow(std::vector<std::vector<int>> &skok,int &a,int &b) {
        int wynik = 0;

        for(int k = 17; k >= 0; --k) {

            if(skok[k][a] < b) {
                a = skok[k][a];
                wynik += (1 << k);
            }
        }
        return wynik + 1;
    }
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        std::vector<std::pair<int, int>> posortowane(n);
        for (int i = 0; i < n; ++i) posortowane[i] = {nums[i], i};
        sort(posortowane.begin(), posortowane.end());

        std::vector<int> grupa(n);
        int ktora_grupa = 0;
        grupa[posortowane[0].second] = ktora_grupa;

        for (int i = 1; i < n; ++i) {
            if (posortowane[i].first - posortowane[i - 1].first > maxDiff) ++ktora_grupa;
            grupa[posortowane[i].second] = ktora_grupa;
        }

        std::vector<int> pozycja(n);

        for (int i = 0; i < n; ++i) pozycja[posortowane[i].second] = i;
        
        std::vector<int> najdalszy_skok(n);

        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r + 1 < n && posortowane[r + 1].first - posortowane[l].first <= maxDiff) ++r;
            najdalszy_skok[l] = r;
        }

        int LOG = 18; 
        std::vector<std::vector<int>> skok(LOG, std::vector<int>(n));

        for(int i = 0; i < n; ++i) skok[0][i] = najdalszy_skok[i];

        for(int k = 1; k < LOG; ++k) {
            for(int i = 0; i < n; ++i) skok[k][i] = skok[k-1][skok[k-1][i]];
        }
        std::vector<int> minimalne_sciezki(queries.size());
        for (int i{}; i < queries.size(); ++i) {
            int x = queries[i][0];
            int y = queries[i][1];

            if(x == y) {
                minimalne_sciezki[i] = 0;
                continue;
            }

            if(grupa[x] != grupa[y]) {
                minimalne_sciezki[i] = -1;
                continue;
            }

            int u = pozycja[x];
            int v = pozycja[y];

            if(u > v) std::swap(u,v);

            if(v == u) minimalne_sciezki[i] = 0;
    
            else if(nums[x] - nums[y] <= maxDiff && nums[y] - nums[x] <= maxDiff) minimalne_sciezki[i] = 1;
            else minimalne_sciezki[i] = policz_liczbe_skokow(skok,u,v);
        }
        return minimalne_sciezki;
    }
};