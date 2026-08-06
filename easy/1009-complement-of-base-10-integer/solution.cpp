/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<bitset>
#include<cmath>

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int maska = 1;
        while(maska < n) {
            maska = (maska << 1) | 1;
        }
        return (~n) & maska;
    }
};