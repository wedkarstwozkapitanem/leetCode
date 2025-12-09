/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
private:
    int wynik = 0;

    int dfs(const std::vector<std::vector<int>>& graf, const std::vector<int>& values,const int &lisc,const int &rodzic,const int &k) {
        int sum = values[lisc];

        for (const int n : graf[lisc]) {
            if (n == rodzic) continue;
            sum += dfs(graf, values, n, lisc, k) % k;
        }

        if (sum % k == 0) {
            ++wynik;
            return 0;
        }

        return sum;
    }

public:
    int maxKDivisibleComponents(int n, std::vector<std::vector<int>>& edges, std::vector<int>& values, int k) {
        std::vector<std::vector<int>> graf(n);
        for (const auto& edge : edges) {
            graf[edge[0]].push_back(edge[1]);
            graf[edge[1]].push_back(edge[0]);
        }

        if(dfs(graf, values, 0, -1, k) % k) ++wynik;
        return wynik;
    }
};
