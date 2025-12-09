/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        std::vector<std::vector<int>> dp(m + 1,std::vector<int>(n + 1,0));

        for(const auto &i : strs) {
            int liczba0 = std::count(i.begin(),i.end(),'0');
            int liczba1 = i.size() - liczba0;

            for(int z{m};z>=liczba0;--z){
                for(int j{n};j>=liczba1;--j) dp[z][j] = std::max(dp[z][j], dp[z-liczba0][j-liczba1] + 1 );
            }
        }
        
        return dp[m][n];
    }
};