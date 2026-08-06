/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        std::vector<int> prefiksGcd(nums.size());

        int mx = nums[0];
        for(int i{};i<nums.size();++i) {
            mx = std::max(mx,nums[i]);
            prefiksGcd[i] = std::gcd(mx,nums[i]);
        }
        std::sort(prefiksGcd.begin(),prefiksGcd.end());

        long long wynik{};
        for(int i{};i<prefiksGcd.size() / 2;++i) wynik += std::gcd(prefiksGcd[i],prefiksGcd[prefiksGcd.size() - i - 1]);
        
        return wynik;
    }
};