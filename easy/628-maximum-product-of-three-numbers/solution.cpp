/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int maks1{INT_MIN},maks2{INT_MIN},maks3{INT_MIN},min1{INT_MAX},min2{INT_MAX};
        for(const auto &i : nums) {
            if(i > maks1) {
                maks3 = maks2;
                maks2 = maks1;
                maks1 = i;
            } else if(i > maks2) {
                maks3 = maks2;
                maks2 = i;
            }
            else if(i > maks3) maks3 = i;
            if(i < min1) {
                min2 = min1;
                min1 = i;
            } else if(i < min2) min2 = i;
        }
        return std::max(maks1 * maks2 * maks3, min1 * min2 * maks1);
    }
};