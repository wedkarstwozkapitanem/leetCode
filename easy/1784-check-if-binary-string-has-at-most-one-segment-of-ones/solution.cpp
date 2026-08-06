/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        int znalezionoJeden = -1;
        for(int i{};i<s.size();++i) {
            if(s[i]=='1' && znalezionoJeden == -1) znalezionoJeden = i;
            else if(s[i] == '1' && znalezionoJeden != i - 1) {
                std::cout << i << ' ' << znalezionoJeden << '\n';
                return false;
            } else if(s[i] == '1') znalezionoJeden = i;
        }
        return true;
    }
};