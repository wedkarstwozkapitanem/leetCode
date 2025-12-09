/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        std::vector<long long> prefiks(nums.size()+1,0);
        for(int i{};i<nums.size();++i) prefiks[i+1] = (prefiks[i] + nums[i]);
        
        long long wynik = std::numeric_limits<long long>::min();
        //for(const auto &i : prefiks) std::cout << i << ' ';

        std::vector<long long> min(nums.size()+1,std::numeric_limits<long long>::max());
        min[0] = 0;
        for(int i{1};i<prefiks.size();++i) {
            int r = i % k;
            if(min[r] != std::numeric_limits<long long>::max()) {
                wynik = std::max(wynik,prefiks[i]-min[r]);
            }
            min[r] = std::min(min[r],prefiks[i]);
        }
        
        return wynik;
    }
};