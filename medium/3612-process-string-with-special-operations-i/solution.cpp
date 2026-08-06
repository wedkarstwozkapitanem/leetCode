/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    string processStr(string s) {
        std::string result;
        for(const auto &i : s) {
            if(i >= 'a' && i <= 'z') result.push_back(i);
            else if(i == '*' && !result.empty()) result.pop_back();
            else if(i == '#') result += result;
            else if(i == '%') std::reverse(result.begin(),result.end());
        }
        return result;
    }
};