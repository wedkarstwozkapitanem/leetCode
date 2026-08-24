/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<algorithm>

class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(),s.end(),s.begin(),[&](char a){
            return std::tolower(static_cast<unsigned char>(a));
        });

        const auto ostatni_znak = std::remove_if(s.begin(),s.end(),[&](const auto &a){
            return !std::isalnum(static_cast<unsigned char>(a));
        });

        const auto kopia = s;
        std::reverse(s.begin(),ostatni_znak);
        return s == kopia;
    }
};