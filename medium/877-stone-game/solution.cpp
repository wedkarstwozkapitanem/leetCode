/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
private:
    int sumuj(vector<int>& piles,int lewy,int prawy,std::vector<std::vector<int>> &dp) {
        if(lewy == prawy) return piles[lewy];
        if(dp[lewy][prawy] != INT_MIN) return dp[lewy][prawy];
        int bierzLewy = piles[lewy] - this->sumuj(piles,lewy + 1, prawy,dp);
        int bierzPrawy = piles[prawy] - this->sumuj(piles,lewy, prawy - 1,dp);
        return dp[lewy][prawy] = std::max(bierzLewy,bierzPrawy);
    }
public:
    bool stoneGame(vector<int>& piles) {
        //std::vector<std::vector<int>> dp(piles.size(),std::vector<int>(piles.size(),INT_MIN));
        return true;//this->sumuj(piles,0,piles.size() - 1,dp) > 0;
    }
};