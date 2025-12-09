/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<set>

class Solution {
private:
    std::vector<int> reprezentanci;
    int find(int a) {
        if (a != reprezentanci[a]) reprezentanci[a] = find(reprezentanci[a]);
        return reprezentanci[a];
    }

    void polocz(int a,int b) {
        const int ar = find(a),ab=find(b);
        if(ar != ab) reprezentanci[ar] = ab;
    }
    std::vector<std::set<int>> loczenie(vector<vector<int>>& connections,int c) {
        std::vector<std::set<int>> poloczenia(c+1);
        for(const auto &i : connections) polocz(i[0],i[1]);
         
        for(int i{};i<=c;++i) poloczenia[find(i)].insert(i);
        
        return poloczenia;
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        std::vector<int> wynik;
        reprezentanci.resize(c+1);

        for(int i{};i<=c;++i) reprezentanci[i] = i;
        std::unordered_map<int,bool> aktywny;

        auto poloczenia = loczenie(connections,c);
        for(const auto &i : queries) {
            const short zapytanie = i[0];
            const int ktory = i[1];
            const int lider = find(ktory);
            if(zapytanie == 1) {
                if(!aktywny[ktory]) wynik.push_back(ktory);
                else {
                    if(poloczenia[lider].empty()) wynik.push_back(-1);
                    else wynik.push_back(*poloczenia[lider].begin());
                }
            } else if(zapytanie == 2) {
                aktywny[ktory] = true;
                poloczenia[lider].erase(ktory);
            }
        }
        return wynik;
    }
};