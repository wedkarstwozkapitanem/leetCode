/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        std::vector<int> ostatnieWystopienie(26,0);
        for(int i{};i<s.size();++i) ostatnieWystopienie[s[i] - 'a'] = i;

        std::vector<bool> uzyto(26,false);
        std::string wynik{};
        for(int i{};i<s.size();++i) {
            if(uzyto[s[i] - 'a']) continue;
            while(!wynik.empty() && wynik.back() > s[i] && ostatnieWystopienie[wynik.back() - 'a'] > i) {
                uzyto[wynik.back() - 'a'] = false;
                wynik.pop_back();
            }
            wynik.push_back(s[i]);
            uzyto[s[i] - 'a'] = true;
        }
        return wynik;
    }
};