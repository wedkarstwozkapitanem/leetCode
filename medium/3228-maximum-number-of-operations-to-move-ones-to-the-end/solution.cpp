/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int maxOperations(string s) {
        int operacje{}, liczba1{};

        for (int i{}; i < s.size() - 1; ++i) {
            if (s[i] == '1')
                ++liczba1;
            if (s[i] == '1' && s[i + 1] == '0')
                operacje += liczba1;
        }

        return operacje;
    }
};