/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        std::vector<std::string> wynik;
        std::map<std::string,std::vector<std::string>> wybrane;

        const std::string kategorie[] = {"electronics", "grocery", "pharmacy", "restaurant"};

        for(int i{};i<code.size();++i)  {
            if(!isActive[i]) continue;
            bool znaleziono{false};
            for(const auto &k : kategorie) {
                if(businessLine[i] == k) {
                    znaleziono = true;
                    break;
                }
            }
            if(!znaleziono || code[i].empty()) continue;
            for(const auto &c : code[i]) {
                if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<='9')) continue;
                else if(c != '_') {
                    znaleziono = false;
                    break;
                }
            }
            if(znaleziono)
            wybrane[businessLine[i]].push_back(code[i]);
        }

        for(const auto &i : kategorie) {
            std::sort(wybrane[i].begin(),wybrane[i].end());
            for(const auto &j : wybrane[i]) wynik.push_back(j);
        }
        
        return wynik;
    }
};