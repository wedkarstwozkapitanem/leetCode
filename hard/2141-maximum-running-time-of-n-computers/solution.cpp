/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long suma{};
        for(const auto &i : batteries) suma += i;
        long long p{};
        long long k = suma / n;
        while(p<k) {
            long long m = (p+k+1) / 2;
            long long dostepna{};
            for (const long long &b :  batteries) dostepna += min(b,m);
            if(dostepna >= m * n) p = m;
            else k = m - 1; 
        }
        return p;
    }
};