/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int maxProduct(int n) {
        short maks1{},maks2{};
        while(n) {
            short cyfra = (n % 10);
            if(cyfra > maks1) {
                maks2 = maks1;
                maks1 = cyfra;
            }
            else if(cyfra > maks2) maks2 = cyfra;
            n /= 10;
        }
        
        return maks1 * maks2;
    }
};