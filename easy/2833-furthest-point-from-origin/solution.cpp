/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L{},R{};

        for(const auto &i : moves) {
            if(i == 'L') ++L;
            else if(i == 'R') ++R;
        }
        int polozenie{};
        for(const auto &i : moves) {
            if(i == 'L') --polozenie;
            else if(i == 'R') ++polozenie;
            else if(L > R) --polozenie;
            else ++polozenie;
        }
        return std::abs(polozenie);
    }
};