
/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int mod[] = {0,0,0};
        for(const auto &i : stones) ++mod[i % 3];
        if(mod[0] % 2 == 0) return mod[1] && mod[2];
        return std::abs(mod[2] - mod[1]) > 2;
    }
};