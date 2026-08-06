/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int prawaSuma = std::accumulate(nums.begin(),nums.end(),0),lewaSuma{};
        for(int i{0};i<nums.size();++i) {
            const auto ak = nums[i];
            lewaSuma += ak;
            prawaSuma -= ak;
            nums[i] = std::abs((lewaSuma - ak) - prawaSuma);
        }
        return nums;
    }
};