/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        if(s.empty()) return 0;
        if(s.size() == 1) return 1;
        
        std::unordered_map<char,int> czestotliowsc;
        int maks{},lewy{};
        for(int i{};i<s.size();++i) {
            ++czestotliowsc[s[i]];
            while(czestotliowsc[s[i]] > 2) {
                --czestotliowsc[s[lewy]];
                ++lewy;
            }
            maks = std::max(maks,i - lewy + 1);
        }
        return maks;
    }
};