/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int smallestNumber(int n, int t) {

        while(true) {
            int n_k{n},iloczyn{1};
            while(n_k > 0) {
                iloczyn *= n_k % 10;
                n_k /= 10;
            }
            if(!(iloczyn % t)) return n;
            ++n;
        }
        return n;
    }
};