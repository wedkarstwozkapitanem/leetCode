/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<algorithm>
#include <functional>

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        std::sort(capacity.begin(),capacity.end(),greater<int>());

        const int cala_suma_jablek = std::accumulate(apple.begin(),apple.end(),0);
        int aktualna{};

        for(int i{};i<capacity.size();++i) {
            aktualna += capacity[i];
            if(aktualna >= cala_suma_jablek) return i + 1;
        }
        return capacity.size();
    }
};