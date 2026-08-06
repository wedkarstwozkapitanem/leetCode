/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
private:
    int gcd(int a,int b) {
        if(!a) return b;
        if(!b) return a;
        return std::gcd(a,b);
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        std::vector<std::vector<long long>> dp(201,std::vector<long long>(201,0));
        dp[0][0] = 1;
        for(const auto &liczba : nums) {
            auto tmpdp = dp;
            for(int i{};i<=200;++i) {
                for(int j{};j<=200;++j) {
                    if(!dp[i][j]) continue;
                    int gcd = this->gcd(i,liczba);
                    tmpdp[gcd][j] = (tmpdp[gcd][j] + dp[i][j]) % MOD;

                    gcd = this->gcd(j,liczba);
                    tmpdp[i][gcd] = (tmpdp[i][gcd] + dp[i][j]) % MOD;
                }
            }
            dp = tmpdp;
        }
        int wynik{};
        for(int i{};i<=200;++i)  wynik = (wynik + dp[i][i]) % MOD;
        
        return wynik - 1;
    }
};