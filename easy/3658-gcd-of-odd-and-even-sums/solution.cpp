/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int gcdOfOddEvenSums(int n) { 
        return std::gcd(n * n, n*(n - 1));
    }
};