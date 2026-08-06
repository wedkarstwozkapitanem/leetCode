/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) return -1;        
        if(haystack == needle) return 0;
        for(int i{};i<=haystack.size() - needle.size();++i) {
            if(haystack[i] == needle[0]) {
                bool pasuje{true};
                for(int j{1}; j < needle.size();++j) {
                    if(haystack[i+j] != needle[j]) {
                        pasuje = false;
                        break;
                    }
                }
                if(pasuje) return i;
            }
        }
            return -1;
    }
};