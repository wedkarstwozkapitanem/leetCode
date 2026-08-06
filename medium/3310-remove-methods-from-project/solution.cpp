/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
private:
     void dfs(const int aktualny,const std::vector<std::vector<int>> &graf,std::vector<int> &odwiedzone) {
        odwiedzone[aktualny] = true;
        for(const auto &i : graf[aktualny]) if(!odwiedzone[i]) dfs(i,graf,odwiedzone);
    }

 
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        std::vector<std::vector<int>> graf(n);
        std::vector<int> odwiedzone(n,0);
        for(const auto &i : invocations) graf[i[0]].push_back(i[1]);

        dfs(k,graf, odwiedzone);

        std::vector<int> wynik;
        for(const auto &i : invocations) {
            const auto a = i[0];
            const auto b = i[1];
            if(!odwiedzone[a] && odwiedzone[b]) {
                for(int i{};i<n;++i) wynik.push_back(i);
                return wynik;
            }
        }
        for(int i{};i<n;++i)  if(!odwiedzone[i]) wynik.push_back(i);
        
        return wynik;
    }
};