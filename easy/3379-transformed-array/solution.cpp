/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<vector>

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        std::vector<int> result(nums.size());

        for(int i{};i<nums.size();++i) {
            const int p = nums[i];
            if(p==0) {
                result[i] = nums[i];
                continue;
            }
            if(p > 0) result[i] = nums[((i + p) % nums.size()  + nums.size()) % nums.size()];
            else result[i] = nums[((i - std::abs(p) % nums.size()) + nums.size()) % nums.size()];
        } 
        return result;
    }
};