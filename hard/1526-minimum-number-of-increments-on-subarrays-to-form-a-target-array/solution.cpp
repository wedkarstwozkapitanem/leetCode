/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int wynik{target[0]};
        for(size_t i{1};i<target.size();++i) {
            if(target[i] > target[i-1]) wynik += target[i] - target[i-1];
        }
        return wynik;
    }
};