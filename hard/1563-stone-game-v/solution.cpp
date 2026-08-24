/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        std::vector<int> prefiks(n + 1, 0);

        for (int i = 0; i < n; i++) prefiks[i + 1] = prefiks[i] + stoneValue[i];
        
        std::vector<std::vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                for (int k = i; k < j; k++) {
                    int lewy = prefiks[k + 1] - prefiks[i];
                    int prawy = prefiks[j + 1] - prefiks[k + 1];

                    if (lewy < prawy) {
                        dp[i][j] = max(
                            dp[i][j],
                            lewy + dp[i][k]
                        );
                    }
                    else if (lewy > prawy) {

                        dp[i][j] = max(
                            dp[i][j],
                            prawy + dp[k + 1][j]
                        );
                    }
                    else {
 
                        dp[i][j] = max(
                            dp[i][j],
                            lewy + max(
                                dp[i][k],
                                dp[k + 1][j]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};