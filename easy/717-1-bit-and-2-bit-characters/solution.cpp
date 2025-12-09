/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        for(size_t i{};i<bits.size()-1;++i) {
            const int b = bits[i];
            if(!b) continue;
            if(b==1) ++i;
            if(i==bits.size()-1) return false;
        }

        return true;
    }
};