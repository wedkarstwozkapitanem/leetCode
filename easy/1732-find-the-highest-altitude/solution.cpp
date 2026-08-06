/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maks{},aktualna_wysokosc{};
        for(int i{};i<gain.size();++i) {
            aktualna_wysokosc += gain[i];
            maks = std::max(maks,aktualna_wysokosc);
        }

        return maks;
    }
};