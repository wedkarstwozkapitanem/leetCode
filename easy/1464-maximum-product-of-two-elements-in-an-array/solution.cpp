/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maks1{INT_MIN},maks2{INT_MIN};
        for(const auto &i : nums) {
            if(i > maks1) {
                maks2 = maks1;
                maks1 = i;
            } else if(i > maks2) maks2 = i;
        }
        return (maks1 - 1) * (maks2 - 1);
    }
};