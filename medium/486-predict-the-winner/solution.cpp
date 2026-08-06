/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
private:
    
    int szukaj(const vector<int>& nums,int lewy,int prawy,std::vector<std::vector<int>> &dp) {
        if(lewy == prawy) return nums[lewy];
        if(dp[lewy][prawy] != -1) return dp[lewy][prawy];
        int bierz_lewego = nums[lewy] - this->szukaj(nums,lewy + 1,prawy,dp);
        int bierz_prawego = nums[prawy] - this->szukaj(nums,lewy,prawy - 1,dp);
        return dp[lewy][prawy] = std::max(bierz_lewego,bierz_prawego);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        const int n = nums.size();
        if(!(n % 2)) return true;

        std::vector<std::vector<int>> dp(n,std::vector<int>(n,-1));
        return this->szukaj(nums,0,nums.size()-1,dp) >= 0;
    }
};