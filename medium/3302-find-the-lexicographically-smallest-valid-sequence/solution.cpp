/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        const int n = word1.size(),m = word2.size();
        std::vector<int> najmniejszy_i(m + 1,-1);
        najmniejszy_i[m] = n;
        int p = n - 1;

        for(int i = m - 1;i>=0;--i) {
            while(p >= 0 && word1[p] != word2[i]) --p;
            najmniejszy_i[i] = p;
            if(p>=0) --p;
        }
        std::vector<int> wynik;
        wynik.reserve(m);
        
        int j{};
        bool zmiana{false};
        for(int i{};i < n && j < m;++i) {
            if(word1[i] == word2[j]) {
                wynik.push_back(i);
                ++j;
                continue;
            }
            if(!zmiana && najmniejszy_i[j+1] > i ) {
                wynik.push_back(i);
                ++j;
                zmiana = true;
            }
        }
        if(j == m) return wynik;
        return {};
    }
};