/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    char processStr(string s, long long k) {
        const auto r = s.size();
        if(r == 0) return '.';

        std::vector<long long> dl(r+1,0);

        for(int j{};j<r;++j) {
            char i = s[j];
            if(i >= 'a' && i <= 'z') dl[j + 1] = dl[j] + 1;
            else if(i == '*') dl[j + 1] = std::max(0ll,dl[j] - 1);    
            else if(i == '#') dl[j + 1] = dl[j] * 2;
            else if(i == '%') dl[j + 1] = dl[j];
        }

        if(k >= dl[r]) return '.';
        
        for(int i = r - 1;i>=0;--i) {
            const long long wczesniejszadlugosc = (i > 0 ? dl[i] : 0);
            const char aktualnyznak = s[i];
            if( aktualnyznak >= 'a' && aktualnyznak <= 'z') {
                if(wczesniejszadlugosc == k) return aktualnyznak;
            } else if(aktualnyznak == '#') {
                if(k >= wczesniejszadlugosc &&  wczesniejszadlugosc != 0) k %= wczesniejszadlugosc;
            } else if(aktualnyznak == '%') {
                k = wczesniejszadlugosc - k - 1;
            }
        }
        return '.';
    }
};