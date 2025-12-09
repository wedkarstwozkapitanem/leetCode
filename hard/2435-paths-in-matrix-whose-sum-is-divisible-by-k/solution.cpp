/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<queue>
#include<vector>

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        if(grid.empty()) return 0;
        if(grid[0].size() <= 1 && grid.size() <= 1) return (grid[0][0] % k) == 0;

        constexpr int MOD = 1e9 + 7;
        const int n = grid.size(),m = grid[0].size();
        std::vector<std::vector<std::vector<long long>>> dp(n,std::vector<std::vector<long long>>(m,std::vector<long long>(k,0)));

        
        dp[0][0][grid[0][0]%k] = 1;
        
        for(int i{};i<n;++i) {
            for(int j{};j<m;++j){
                const int aktualny = grid[i][j] % k;

                if (i>0) {
                    for(int p{};p<k;++p) {
                        int ktory = (aktualny + p) % k;
                        dp[i][j][ktory] = (dp[i][j][ktory] + dp[i-1][j][p]) % MOD; 
                    }
                }

                if (j > 0) {
                    for(int p{};p<k;++p) {
                        int ktory = (aktualny + p) % k;
                        dp[i][j][ktory] = (dp[i][j][ktory] + dp[i][j-1][p]) % MOD; 
                    }
                }


            }
        }

        return dp[n - 1][m - 1][0] % MOD;
    }
};