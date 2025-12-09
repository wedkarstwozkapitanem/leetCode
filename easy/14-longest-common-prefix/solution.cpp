/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        int licznik{};
        std::string txt{""};
        while(true){
            if(strs[0].size() <= licznik) return txt;
            char letter = strs[0][licznik];
            for(const auto &i : strs) {
                if(i.size() <= licznik) return txt;
                if(i[licznik] != letter) return txt;
            }

            txt.push_back(letter);
            licznik++;
        }
        return txt;
    }
};