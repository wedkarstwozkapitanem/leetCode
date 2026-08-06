/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int climbStairs(int n) {
        long long a{1},b{1};
        for(int i{};i<n;++i) {
            int tmp = b;
            b += a;
            a = tmp;
        }
        return static_cast<int>(a);
    }
};