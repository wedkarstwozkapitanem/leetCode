/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool ostatni = n % 2;
        n /= 2;
        while(n) {
            if(ostatni == n % 2) return false; 
            ostatni = n % 2;
            n/=2;
        } 
        return true;       
    }
};