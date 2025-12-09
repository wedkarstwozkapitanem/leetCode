/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int min1 = 1e4,min2 = 1e4,min3 = 1e4,min4 = 1e4;
        int suma{};
        for(const auto &i : nums) {
            suma += i;
            if(!(i%3)) continue;
            if(i%3 == 1) {
                if(i < min1) {
                    min2 = min1;
                    min1 = i;
                } else if(i < min2) min2 = i;
                
            } else {
                if(i < min3) {
                    min4 = min3;
                    min3 = i;
                } else if(i < min4) min4 = i;
            }
        }

        if(suma % 3 == 1) suma -= std::min(min1,min3 + min4);
        else if(suma % 3 == 2) suma -= std::min(min3,min1+min2);
        
        return suma;
    }
};
