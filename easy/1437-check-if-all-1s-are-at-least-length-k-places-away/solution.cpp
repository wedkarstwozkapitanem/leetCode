/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int znalezione{-1};

        for(int i{};i<nums.size();++i) {
            if(nums[i] == 1) {
                if(i - znalezione <= k  && znalezione != -1) return false;
                znalezione = i;
            } 
        }
        return true;
    }
};